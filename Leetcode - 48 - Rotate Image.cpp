class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); 

        for (int row = 0; row < n / 2; row++) {
            for (int col = row; col < (n - row -  1); col++) {
                int timer = 1;
                int curx = row; 
                int cury = col; 
                int curValue = matrix[curx][cury];
                int temp = 0;
                
                int nextx; 
                int nexty;
                while (timer <= 4) {
                    nextx = cury;
                    nexty = n - curx - 1; 
                    temp = matrix[nextx][nexty];
                    matrix[nextx][nexty] = curValue;
                    curValue = temp;
                    curx = nextx; 
                    cury = nexty;
                    timer += 1;
                }
            }
        }
    }
};
