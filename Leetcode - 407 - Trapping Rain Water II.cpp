class Solution {
public:
    struct Cell {
        int x, y, h; 

        Cell(int x, int y, int h) {
            this->x = x;
            this->y = y;
            this->h = h;
        }

        bool operator>(const Cell& other) const {
            return h > other.h;
        }
    };

    const static int MAX_LENGTH = 200; 
    int nrow; 
    int ncol; 
    int water[MAX_LENGTH][MAX_LENGTH];
    bool check[MAX_LENGTH][MAX_LENGTH];

    const static int MAX_DIRECTIONS = 4; 
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq; 
        nrow = heightMap.size(); 
        ncol = heightMap[0].size(); 
        for (int col = 0; col < ncol; col++) {
            pq.push(Cell(0, col, heightMap[0][col]));
            pq.push(Cell(nrow - 1, col, heightMap[nrow - 1][col]));
        }
        for (int row = 1; row < nrow - 1; row++) {
            pq.push(Cell(row, 0, heightMap[row][0]));
            pq.push(Cell(row, ncol - 1, heightMap[row][ncol - 1]));
        }

        while (pq.empty() == false) {
            Cell front = pq.top(); pq.pop(); 
            int curx = front.x; 
            int cury = front.y; 
            int curh = front.h;
            check[curx][cury] = true;

            for (int dir = 0; dir < MAX_DIRECTIONS; dir++) {
                int newx = curx + dx[dir];
                int newy = cury + dy[dir];
                if (newx >= 0 && newx < nrow && newy >= 0 && newy < ncol && check[newx][newy] == false) {
                    water[newx][newy] = max(0, curh - heightMap[newx][newy]);
                    int newh = max(heightMap[newx][newy], heightMap[curx][cury]);
                    pq.push(Cell(newx, newy, newh));
                }
            }
        }
        int answer = 0; 
        for (int row = 0; row < nrow; row++) {
            for (int col = 0; col < ncol; col++) {
                cout << row << "/" << col << " : " << water[row][col] << " ";
                answer += water[row][col];
            }
            cout << endl;
        }
        return answer; 
    }
};
