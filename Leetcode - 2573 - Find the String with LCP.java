class Solution {
    private int[] mask; 
    private int[] parMask;
    private int nRow; 
    private int nCol; 
    private char[] output;

    private int findMask(int node) {
        if (parMask[node] != node) {
            parMask[node] = findMask(parMask[node]); 
        }
        return parMask[node];
    }

    private boolean isSameNode(int u, int v) {
        return findMask(u) == findMask(v);
    }

    private void mergeNode(int u, int v) {
        int paru = findMask(u);
        int parv = findMask(v);

        if (paru != parv) {
            parMask[paru] = parv;
        }
    }

    public boolean recheck(String res, int[][] lcp) {
        int n = res.length();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int expected = 0;
                if (res.charAt(i) == res.charAt(j)) {
                    if (i + 1 < n && j + 1 < n) {
                        expected = 1 + lcp[i + 1][j + 1];   
                    } else {
                        expected = 1;
                    }
                }
                if (lcp[i][j] != expected) {
                    return false;
                }
            }
        }
        return true;
    }

    public String findTheString(int[][] lcp) {
        nRow = lcp.length; 
        nCol = lcp[0].length; 
        mask = new int[nRow]; 
        parMask = new int[nRow];
        for (int row = 0; row < nRow; row++) {
            parMask[row] = row;
            mask[row] = row;
        }
        output = new char[nRow];

        if (nRow == 1 && nCol == 1 && lcp[0][0] == 0) {
            return "";
        }

        for (int row = 0; row < nRow; row++) {
            for (int col = 0; col < nCol; col++) {
                if (lcp[row][col] != lcp[col][row]) {
                    return "";
                } 
                if (row == col && lcp[row][col] != (nRow - row)) {
                    return ""; 
                }
            }
        }

        for (int row = 0; row < nRow; row++) {
            for (int col = 0; col < nCol; col++) {
                int sameAmount = lcp[row][col];
                if (sameAmount > 0) {
                    for (int offSet = 0; offSet < sameAmount; offSet++) {
                        if (row + offSet >= nRow || col + offSet >= nRow) {
                            return "";
                        }
                        mergeNode(row + offSet, col + offSet);
                    }
                }
            }
        }

        char cur = 'a';

        for (int node = 0; node < nRow; node++) {
            int idx = findMask(node);
            if (output[idx] == '\0') {
                output[idx] = cur;
                if (cur > 'z') {
                    return "";
                }
                cur++;
            }
        }

        for (int node = 0; node < nRow; node++) {
            System.out.print(findMask(node) + " ");
        }

        StringBuilder res = new StringBuilder();

        for (int node = 0; node < nRow; node++) {
            res.append(output[findMask(node)]);
        }

        return (recheck(res.toString(), lcp) == true ? res.toString() : "");
    }
}
