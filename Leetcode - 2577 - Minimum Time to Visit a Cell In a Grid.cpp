class State {
public:
    int row; 
    int col; 
    int time; 

    State(int row, int col, int time) {
        this->row = row; 
        this->col = col; 
        this->time = time;
    }

    bool operator> (const State& other) const {
        return time > other.time;
    }
};

class Solution {
    priority_queue<State, vector<State>, greater<State>> queueState;
    vector<vector<int>> timeTake;
    int num_row; 
    int num_col; 

    const static int AMOUNT_DIRECTION = 4;
    int dx[AMOUNT_DIRECTION] = {0,0,1,-1};
    int dy[AMOUNT_DIRECTION] = {1,-1,0,0};

    public:
        bool isValidPosition(int row, int col) {
            return (row >= 0 && row < num_row && col >= 0 && col < num_col);
        }

        int minimumTime(vector<vector<int>>& grid) {
            num_row = grid.size(); 
            num_col = grid[0].size(); 
            timeTake.assign(num_row, vector<int>(num_col, INT_MAX));

            for (int row = 0; row < num_row; row++) {
                for (int col = 0; col < num_col; col++) {
                    timeTake[row][col] = INT_MAX;
                }
            }
            timeTake[0][0] = 0;
            queueState.push(State(0,0,0));

            while (queueState.empty() == false) {
                State currentState = queueState.top(); 
                queueState.pop(); 
                int currentRow = currentState.row;
                int currentCol = currentState.col; 
                int currentTime = currentState.time; 

                if (currentRow == num_row - 1 && currentCol == num_col - 1) {
                    continue;
                }

                if (currentTime > timeTake[currentRow][currentCol]) {
                    continue;
                }

                for (int direction = 0; direction < AMOUNT_DIRECTION; direction++) {
                    int newRow = currentRow + dx[direction];
                    int newCol = currentCol + dy[direction]; 
                    int newTime = currentTime + 1; 

                    if (isValidPosition(newRow, newCol) == false || newTime >= timeTake[newRow][newCol]) {
                        continue;
                    } else if (isValidPosition(newRow, newCol) && newTime < timeTake[newRow][newCol] && newTime >= grid[newRow][newCol]) {
                        timeTake[newRow][newCol] = newTime;
                        queueState.push(State(newRow, newCol, newTime));
                    } else if (isValidPosition(newRow, newCol) && newTime < timeTake[newRow][newCol] && newTime < grid[newRow][newCol]) {
                        int timeRemain = grid[newRow][newCol] - newTime; 
                        for (int directionLoop = 0; directionLoop < AMOUNT_DIRECTION; directionLoop++) {
                            int newRowLoop = currentRow + dx[directionLoop];
                            int newColLoop = currentCol + dy[directionLoop]; 
                            if (isValidPosition(newRowLoop, newColLoop) && newTime >= grid[newRowLoop][newColLoop]) {
                                newTime += (timeRemain + 1) / 2 * 2;
                                if (newTime < timeTake[newRow][newCol]) {
                                    timeTake[newRow][newCol] = newTime;
                                    queueState.push(State(newRow, newCol, newTime));
                                }
                                break;
                            }
                        }
                    }
                }
            }
        int answer = ((timeTake[num_row - 1][num_col - 1] != INT_MAX) ? timeTake[num_row - 1][num_col - 1] : -1);
        return answer;
    }
};
