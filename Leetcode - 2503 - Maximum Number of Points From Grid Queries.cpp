class Solution {
public:
    bool check[1005][1005];
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int n, m;

    bool isOk(pair<int, int> coordinate) {
        if (coordinate.first >= 0 && coordinate.first < n && coordinate.second >= 0 && coordinate.second < m && check[coordinate.first][coordinate.second] == false) {
            return true;
        }
        return false;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        n = grid.size(); 
        m = grid[0].size();
        vector<pair<int, int>> new_queries; 
        for (int index = 0; index < queries.size(); index++) {
            auto query = queries[index];
            new_queries.push_back(pair<int, int>(query, index));
        }
        sort(new_queries.begin(), new_queries.end());

        int current_answer = 0;
        vector<int> answer(queries.size(), 0);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for (pair<int, int>& query : new_queries) {
            int query_value = query.first;
            int index = query.second;

            if (query_value > grid[0][0] && check[0][0] == false) {
                check[0][0] = true;
                pq.push(pair<int, pair<int, int>>(grid[0][0], pair<int, int>(0,0)));
            }

            while (pq.empty() == false) {
                auto front = pq.top();
                int cell_value = front.first;
                pair<int, int> cell_coordinate = front.second;
                if (cell_value >= query_value) {
                    break;
                }
                pq.pop(); current_answer += 1;
                for (int way = 0; way < 4; way++) {
                    pair<int, int> new_coordinate = pair<int, int>(cell_coordinate.first + dx[way], cell_coordinate.second + dy[way]);
                    if (isOk(new_coordinate)) {
                        check[new_coordinate.first][new_coordinate.second] = true;
                        pq.push(pair<int, pair<int, int>>(grid[new_coordinate.first][new_coordinate.second], new_coordinate));
                    }
                }
            }
            answer[index] = current_answer;
        }
        return answer;
    }
};
