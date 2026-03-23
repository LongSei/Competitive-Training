class Solution {
    private int AMOUNT_STATE = 2;
    private int POS = 1; 
    private int NEG = 0;
    private int nRow; 
    private int nCol; 
    private long[][][] maxProd; 
    private boolean[][][] isExist; 
    private final int MOD = 1000000007;

    public int maxProductPath(int[][] grid) {
        nRow = grid.length;
        nCol = grid[0].length;

        maxProd = new long[nRow][nCol][AMOUNT_STATE];
        isExist = new boolean[nRow][nCol][AMOUNT_STATE];
        maxProd[0][0][POS] = (grid[0][0] >= 0 ? grid[0][0] : 0);
        maxProd[0][0][NEG] = (grid[0][0] < 0 ? grid[0][0] : 0);
        isExist[0][0][POS] = (grid[0][0] >= 0 ? true : false);
        isExist[0][0][NEG] = (grid[0][0] < 0 ? true : false);

        for (int row = 0; row < nRow; row++) {
            for (int col = 0; col < nCol; col++) {
                if (grid[row][col] == 0) {
                    isExist[nRow - 1][nCol - 1][POS] = true;
                }
            }
        }

        for (int row = 0; row < nRow; row++) {
            for (int col = 0; col < nCol; col++) {
                if (col + 1 < nCol) {
                    int nextCellState = grid[row][col + 1] > 0 ? POS : NEG; 
                    if (nextCellState == POS) {
                        maxProd[row][col + 1][POS] = Math.max(
                                                        maxProd[row][col + 1][POS], 
                                                        (maxProd[row][col][POS] != 0 ? maxProd[row][col][POS] : 0) * grid[row][col + 1]
                                                    );
                        isExist[row][col + 1][POS] |= (isExist[row][col][POS] == true ? true : false);
                        maxProd[row][col + 1][NEG] = Math.min(
                                                        maxProd[row][col + 1][NEG], 
                                                        (maxProd[row][col][NEG] != 0 ? maxProd[row][col][NEG] : 0) * grid[row][col + 1]
                                                    );
                        isExist[row][col + 1][NEG] |= (isExist[row][col][NEG] == true ? true : false);
                    } else {
                        maxProd[row][col + 1][POS] = Math.max(
                                                        maxProd[row][col + 1][POS], 
                                                        (maxProd[row][col][NEG] != 0 ? maxProd[row][col][NEG] : 0) * grid[row][col + 1]
                                                    );
                        isExist[row][col + 1][POS] |= (isExist[row][col][NEG] == true ? true : false);
                        maxProd[row][col + 1][NEG] = Math.min(
                                                        maxProd[row][col + 1][NEG], 
                                                        (maxProd[row][col][POS] != 0 ? maxProd[row][col][POS] : 0) * grid[row][col + 1]
                                                    );  
                        isExist[row][col + 1][NEG] |= (isExist[row][col][POS] == true ? true : false);
                    }
                } 

                if (row + 1 < nRow) {
                    int nextCellState = grid[row + 1][col] > 0 ? POS : NEG; 
                    if (nextCellState == POS) {
                        maxProd[row + 1][col][POS] = Math.max(
                                                        maxProd[row + 1][col][POS], 
                                                        (maxProd[row][col][POS] != 0 ? maxProd[row][col][POS] : 0) * grid[row + 1][col]
                                                    );
                        isExist[row + 1][col][POS] |= (isExist[row][col][POS] == true ? true : false);
                        maxProd[row + 1][col][NEG] = Math.min(
                                                        maxProd[row + 1][col][NEG], 
                                                        (maxProd[row][col][NEG] != 0 ? maxProd[row][col][NEG] : 0) * grid[row + 1][col]
                                                    );
                        isExist[row + 1][col][NEG] |= (isExist[row][col][NEG] == true ? true : false);
                    } else {
                        maxProd[row + 1][col][POS] = Math.max(
                                                        maxProd[row + 1][col][POS], 
                                                        (maxProd[row][col][NEG] != 0 ? maxProd[row][col][NEG] : 0) * grid[row + 1][col]
                                                    );
                        isExist[row + 1][col][POS] |= (isExist[row][col][NEG] == true ? true : false);
                        maxProd[row + 1][col][NEG] = Math.min(
                                                        maxProd[row + 1][col][NEG], 
                                                        (maxProd[row][col][POS] != 0 ? maxProd[row][col][POS] : 0) * grid[row + 1][col]
                                                    );  
                        isExist[row + 1][col][NEG] |= (isExist[row][col][POS] == true ? true : false);
                    }
                }
            }
        }

        return (isExist[nRow - 1][nCol - 1][POS] == true ? (int) (maxProd[nRow - 1][nCol - 1][POS] % MOD) : -1);
    }
}
