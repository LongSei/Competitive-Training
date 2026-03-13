class Solution {
    private int[][] masked;
    private int NROW; 
    private int NCOL; 
    private int[] xDir = {0,0,-1,1};
    private int[] yDir = {1,-1,0,0};
    private int AMOUNT_DIR = 4;
    private int counter; 

    private boolean isOk(char[][] grid, char curChar, int row, int col) {
        return (row >= 0 && row < NROW && col >= 0 && col < NCOL) && (curChar == grid[row][col]);
    }

    private boolean dfs(char[][] grid, int curRow, int curCol, int parRow, int parCol) {
        boolean res = false;
        for (int dir = 0; dir < AMOUNT_DIR; dir++) {
            int newX = curRow + xDir[dir];
            int newY = curCol + yDir[dir];

            if (isOk(grid, grid[curRow][curCol], newX, newY) && (newX != parRow || newY != parCol)) {
                if (masked[newX][newY] == masked[curRow][curCol]) {
                    return true;
                }
                masked[newX][newY] = masked[curRow][curCol];
                res |= dfs(grid, newX, newY, curRow, curCol);
            }
        }
        return res;
    }

    public boolean containsCycle(char[][] grid) {
        NROW = grid.length; 
        NCOL = grid[0].length; 
        masked = new int[NROW + 1][NCOL + 1];
        counter = 0; 
        
        for (int row = 0; row < NROW; row++) {
            for (int col = 0; col < NCOL; col++) {
                if (masked[row][col] == 0) {
                    counter++; 
                    masked[row][col] = counter;
                    if (dfs(grid, row, col, row, col)) {
                        return true;
                    }
                }
            }
        }

        for (int row = 0; row < NROW; row++) {
            for (int col = 0; col < NCOL; col++) { 
                System.out.print(masked[row][col] + " ");
            }
            System.out.println("");
        }

        return false;
    }
}
