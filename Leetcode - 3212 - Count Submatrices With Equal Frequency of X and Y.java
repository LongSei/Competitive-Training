class Solution {
    private int[][][] amountOfElement; 
    private int AMOUNT_OF_MASK = 2;
    private int maskX = 0;
    private int maskY = 1;
    private int nRow;
    private int nCol; 

    public int numberOfSubmatrices(char[][] grid) {
        nRow = grid.length; 
        nCol = grid[0].length;
        amountOfElement = new int[nRow + 5][nCol + 5][AMOUNT_OF_MASK];
        int res = 0;

        for (int row = 1; row <= nRow; row++) {
            for (int col = 1; col <= nCol; col++) {
                amountOfElement[row][col][maskX] = amountOfElement[row - 1][col][maskX] + amountOfElement[row][col - 1][maskX] - amountOfElement[row - 1][col - 1][maskX] + (grid[row - 1][col - 1] == 'X' ? 1 : 0);
                amountOfElement[row][col][maskY] = amountOfElement[row - 1][col][maskY] + amountOfElement[row][col - 1][maskY] - amountOfElement[row - 1][col - 1][maskY] + (grid[row - 1][col - 1] == 'Y' ? 1 : 0);
            }
        }

        for (int row = 1; row <= nRow; row++) {
            for (int col = 1; col <= nCol; col++) {
                if (amountOfElement[row][col][maskX] == amountOfElement[row][col][maskY] && amountOfElement[row][col][maskX] != 0) {
                    res += 1;
                }
            }
        }

        return res;
    }
}
