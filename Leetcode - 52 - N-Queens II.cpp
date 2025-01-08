#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int Result = 0; 
    int size = 0;

    bool check(int x, int y, vector<string>& board) {
        int n = board.size(); 

        // Row Check
        for (int j = 0; j < n; j++) {
            if (board[x][j] == 'Q') {
                return false;
            }
        }

        // Column Check
        for (int i = 0; i < n; i++) {
            if (board[i][y] == 'Q') {
                return false;
            }
        }

        // Diagonal Check
        for (int i = 0; i < n; i++) {
            // Check for positive diagonal
            if (x + i < n && y + i < n && board[x + i][y + i] == 'Q') {
                return false;
            }
            // Check for negative diagonal
            if (x + i < n && y - i >= 0 && board[x + i][y - i] == 'Q') {
                return false;
            }
            // Check for negative diagonal on the opposite side
            if (x - i >= 0 && y + i < n && board[x - i][y + i] == 'Q') {
                return false;
            }
            // Check for positive diagonal on the opposite side
            if (x - i >= 0 && y - i >= 0 && board[x - i][y - i] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void addPos(int x, int y, vector<string>& board) {
        if (board.size() <= x) {
            string currentRow(size, '.'); 
            currentRow[y] = 'Q'; 
            board.push_back(currentRow); 
        } else {
            if (y < board[x].size()) {
                board[x][y] = 'Q'; 
            }
        }
    }

    void removePos(int x, int y, vector<string>& board) {
        board[x][y] = '.';
    }

    void backtrack(int remain, vector<string>& currentResult) {
        if (remain == 0) {
            Result += 1;
            return;
        }
        int row = size - remain; 
        for (int col = 0; col < size; col++) {
            if (check(row, col, currentResult)) {
                addPos(row, col, currentResult);
                backtrack(remain - 1, currentResult);
                removePos(row, col, currentResult);
            }
        }
    }

    int totalNQueens(int n) {
        size = n;
        vector<string> currentResult(n, string(n, '.')); 
        backtrack(n, currentResult);
        return Result;
    }
};
