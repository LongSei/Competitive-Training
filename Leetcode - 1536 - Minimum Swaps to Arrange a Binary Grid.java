class Solution {
    private int[] maxCover;
    private int nRow; 
    private int nCol; 

    private void swapRow(int[][] grid, int firstRow, int secondRow) {
        for (int col = 0; col < nCol; col++) {
            int temp = grid[firstRow][col];
            grid[firstRow][col] = grid[secondRow][col];
            grid[secondRow][col] = temp; 
        }

        int temp = maxCover[firstRow];
        maxCover[firstRow] = maxCover[secondRow];
        maxCover[secondRow] = temp;
    }   

    public int minSwaps(int[][] grid) {
        nRow = grid.length; 
        nCol = grid[0].length; 

        maxCover = new int[nRow]; 
        for (int row = 0; row < nRow; row++) {
            for (int col = nCol - 1; col >= 0; col--) {
                if (grid[row][col] == 1) {
                    maxCover[row] = col;
                    break;
                }
            }
        }    

        int minMove = 0; 
        for (int row = 0; row < nRow; row++) {
            int rowToMove = -1; 
            for (int rowCover = row; rowCover < nRow; rowCover++) {
                if (maxCover[rowCover] <= row) {
                    rowToMove = rowCover;
                    minMove += Math.abs(rowCover - row);
                    break; 
                }
            }

            if (rowToMove == -1) {
                return -1;
            }

            for (int rowMove = rowToMove - 1; rowMove >= row; rowMove--) {
                swapRow(grid, rowMove, rowMove + 1);
            }
        }

        return minMove; 
    }
}
