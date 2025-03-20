class Solution {
public:
    const static int MAXIMUM_VERTICAL = 1e5;
    int parent[MAXIMUM_VERTICAL + 1];
    int cost[MAXIMUM_VERTICAL + 1];

    int find_parent(int node) {
        if (parent[node] != node) {
            return parent[node] = find_parent(parent[node]);
        } 
        return parent[node];
    }

    void merge(int node_x, int node_y, int weight) {
        node_x = find_parent(node_x);
        node_y = find_parent(node_y);

        if (node_x != node_y) {
            parent[node_x] = node_y;
            cost[node_y] = cost[node_x] & cost[node_y] & weight;
        } else {
            cost[node_y] = cost[node_y] & weight;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for (int node = 0; node < n; node++) {
            parent[node] = node;
            cost[node] = 0;
        }

        for (auto& edge : edges) {
            int node_x = edge[0]; 
            int node_y = edge[1];
            int edge_weight = edge[2];

            cost[node_x] = edge_weight;
            cost[node_y] = edge_weight;
        }

        for (auto& edge : edges) {
            int node_x = edge[0]; 
            int node_y = edge[1];
            int edge_weight = edge[2];

            merge(node_x, node_y, edge_weight);
        }

        vector<int> answer;
        for (auto& q : query) {
            int node_x = q[0];
            int node_y = q[1];
            if (find_parent(node_x) == find_parent(node_y)) {
                answer.push_back(cost[find_parent(node_x)]);
            } else {
                answer.push_back(-1);
            }
        }
        return answer;
    }
};
