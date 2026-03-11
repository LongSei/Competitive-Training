class Solution {
    private int[][] longestPath; 
    private int[][] matrixGrid; 
    private int[] xDir = {0,0,1,-1};
    private int[] yDir = {1,-1,0,0};
    private int amountDir = 4;
    private int numRow; 
    private int numCol; 

    public static class PairNode {
        public int x; 
        public int y; 
        public int currentDist;

        public PairNode(int x, int y, int currentDist) {
            this.x = x; 
            this.y = y; 
            this.currentDist = currentDist;
        }
    }
    private Queue<PairNode> queue;

    private boolean inMatrix(PairNode node) {
        return (node.x >= 0 && node.x < numRow && node.y >= 0 && node.y < numCol);
    }

    private boolean isIncreasing(PairNode nodeCur, PairNode nodeNext) {
        return (matrixGrid[nodeCur.x][nodeCur.y] < matrixGrid[nodeNext.x][nodeNext.y]);
    }

    private boolean isLongerPath(PairNode nodeCur, PairNode nodeNext) {
        return (nodeCur.currentDist + 1 > longestPath[nodeNext.x][nodeNext.y]);
    }

    private boolean isOk(PairNode nodeCur, PairNode nodeNext) {
        return (inMatrix(nodeNext) && isIncreasing(nodeCur, nodeNext) && isLongerPath(nodeCur, nodeNext));
    }

    private void findAround(PairNode node) {
        if (node.currentDist < longestPath[node.x][node.y]) {
            return;
        }
        for (int indexDir = 0; indexDir < amountDir; indexDir++) {
            PairNode nodeNext = new PairNode(node.x + xDir[indexDir], node.y + yDir[indexDir], node.currentDist + 1);
            if (isOk(node, nodeNext)) {
                longestPath[nodeNext.x][nodeNext.y] = node.currentDist + 1;
                queue.add(nodeNext);
            }
        }
    }

    public int longestIncreasingPath(int[][] matrix) {
        numRow = matrix.length;
        numCol = matrix[0].length;
        matrixGrid = new int[numRow + 1][numCol + 1];
        for (int indexRow = 0; indexRow < numRow; indexRow++) {
            for (int indexCol = 0; indexCol < numCol; indexCol++) { 
                matrixGrid[indexRow][indexCol] = matrix[indexRow][indexCol];
            }
        }
        longestPath = new int[numRow + 1][numCol + 1];
        queue = new LinkedList<PairNode>();

        for (int indexRow = 0; indexRow < numRow; indexRow++) {
            for (int indexCol = 0; indexCol < numCol; indexCol++) {
                if (longestPath[indexRow][indexCol] == 0) {
                    queue.add(new PairNode(indexRow, indexCol, 1));
                    longestPath[indexRow][indexCol] = 1;
                    while (queue.isEmpty() == false) {
                        PairNode currentNode = queue.poll();
                        findAround(currentNode);
                    }
                }
            }
        }

        int longestPathRes = 0; 
        for (int indexRow = 0; indexRow < numRow; indexRow++) {
            for (int indexCol = 0; indexCol < numCol; indexCol++) { 
                longestPathRes = (longestPathRes > longestPath[indexRow][indexCol] ? longestPathRes : longestPath[indexRow][indexCol]);
            }
        }
        return longestPathRes;
    }
}
