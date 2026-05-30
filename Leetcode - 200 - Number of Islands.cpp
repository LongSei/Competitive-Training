class Solution {
public:
    const static int MAX_DIRECTIONS = 4;
    int dx[MAX_DIRECTIONS] = {0,0,-1,1};
    int dy[MAX_DIRECTIONS] = {1,-1,0,0};

    const static int MAX_LENGTH = 300;
    bool check[MAX_LENGTH][MAX_LENGTH];

    int nrow; 
    int ncol; 

    bool isValidCell(vector<vector<char>>& grid, int row, int col) {
        return (row >= 0 && row < nrow && col >= 0 && col < ncol) && grid[row][col] == '1'; 
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        check[row][col] = true;
        for (int dir = 0; dir < MAX_DIRECTIONS; dir++) {
            int newRow = row + dx[dir];
            int newCol = col + dy[dir];
            if (isValidCell(grid, newRow, newCol) && check[newRow][newCol] == false) {
                dfs(grid, newRow, newCol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        nrow = grid.size(); 
        ncol = grid[0].size();     
        int answer = 0; 
        for (int row = 0; row < nrow; row++) {
            for (int col = 0; col < ncol; col++) {
                if (grid[row][col] == '1' && check[row][col] == false) {
                    dfs(grid, row, col);
                    answer += 1;
                }
            }
        }
        return answer; 
    }
};
