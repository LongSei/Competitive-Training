class Solution {
    private long[][] suffixMatrix;
    private int nRow; 
    private int nCol; 

    private long computeSplitVertical(int begin_col, int end_col) {
        if (begin_col == 0) {
            return suffixMatrix[nRow - 1][end_col];
        }
        return suffixMatrix[nRow - 1][end_col] - suffixMatrix[nRow - 1][begin_col - 1];
    }
    
    private boolean splitVertical() {
        for (int col = 0; col < nCol - 1; col++) {
            if (computeSplitVertical(0, col) == computeSplitVertical(col + 1, nCol - 1)) {
                return true;
            }
        }
        return false;
    }

    private long computeSplitHorizontal(int begin_row, int end_row) {
        if (begin_row == 0) {
            return suffixMatrix[end_row][nCol - 1];
        }
        return suffixMatrix[end_row][nCol - 1] - suffixMatrix[begin_row - 1][nCol - 1];
    }

    private boolean splitHorizontal() {
        for (int row = 0; row < nRow - 1; row++) {
            if (computeSplitHorizontal(0, row) == computeSplitHorizontal(row + 1, nRow - 1)) {
                return true;
            }
        }
        return false;
    }

    public boolean canPartitionGrid(int[][] grid) {
        nRow = grid.length;
        nCol = grid[0].length; 
        suffixMatrix = new long[nRow][nCol];

        for (int row = 0; row < nRow; row++) {
            for (int col = 0; col < nCol; col++) {
                if (row > 0 && col > 0) {
                    suffixMatrix[row][col] = suffixMatrix[row - 1][col] + suffixMatrix[row][col - 1] - suffixMatrix[row - 1][col - 1] + grid[row][col];
                } else if (row > 0) {
                    suffixMatrix[row][col] = suffixMatrix[row - 1][col] + grid[row][col];
                } else if (col > 0) {
                    suffixMatrix[row][col] = suffixMatrix[row][col - 1] + grid[row][col];
                } else {
                    suffixMatrix[row][col] = grid[row][col];
                }
            }
        }

        return (splitHorizontal() || splitVertical());
    }
}
