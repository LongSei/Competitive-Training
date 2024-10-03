bool compareThirdElement(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() < 3 || b.size() < 3) {
        throw std::invalid_argument("Vector must have at least 3 elements");
    }
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

void sorted(std::vector<std::vector<int>>& arr) {
    std::sort(arr.begin(), arr.end(), compareThirdElement);
}
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> pos; 
        sorted(buildings);
        for (auto v : buildings) {
            pos.push_back(v[0]);
            pos.push_back(v[1]);
        }
        sort(pos.begin(), pos.end());
        int indexPos = 0;
        int n = 0;
        for (auto v : buildings) {
            n = max(n, v[1]);
        }
        int index = 0;
        int arrayIndex = 0;
        priority_queue<pair<int, int>> pq; 

        int startIndex = -1;
        int currentMaxi = -1; 

        vector<vector<int>> result; 

        while (index <= n) {
            while (arrayIndex < buildings.size() && buildings[arrayIndex][0] == index) {
                pair<int, int> currentBuildings = pair<int, int>(buildings[arrayIndex][2], buildings[arrayIndex][1]);
                pq.push(currentBuildings);
                arrayIndex += 1;
            }
            while (pq.empty() == false && pq.top().second <= index) {
                auto top = pq.top();
                pq.pop();
                if (pq.empty() && arrayIndex < buildings.size()) {
                    pair<int, int> currentBuildings = pair<int, int>(0, buildings[arrayIndex][1]);
                    pq.push(currentBuildings);
                }
            } 
            if (index == INT_MAX) {break;}
            if (pq.empty() == true) {
                if (index < INT_MAX) {
    index = min(INT_MAX, max(index + 1, pos[indexPos]));
                } else {
                    index = INT_MAX;
                }
                if (indexPos + 1 < pos.size()) indexPos += 1;
                continue;
            }
            int maxi = pq.top().first; 
            if (startIndex == -1) {
                startIndex = index;
                currentMaxi = maxi; 
            }
            if (maxi == currentMaxi) {
                if (index < INT_MAX) {
                    index = min(INT_MAX, max(index + 1, pos[indexPos]));
                } else {
                    index = INT_MAX;
                }
                if (indexPos + 1 < pos.size()) indexPos += 1;
                continue;
            } else {
                result.push_back({startIndex, currentMaxi});
                startIndex = index;
                currentMaxi = maxi;
            }
            if (index < INT_MAX) {
                index = min(INT_MAX, max(index + 1, pos[indexPos]));
            } else {
                index = INT_MAX;
            }
            if (indexPos + 1 < pos.size()) indexPos += 1;
        }
        result.push_back({startIndex, currentMaxi});
        result.push_back({n, 0});

        return result;
    }
};