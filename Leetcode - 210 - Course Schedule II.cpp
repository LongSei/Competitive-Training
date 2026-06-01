class Solution {
public:
    const static int MAX_INDEX = 2000;
    int order[MAX_INDEX];
    vector<int> adjlist[MAX_INDEX];
    bool check[MAX_INDEX];
    
    void dfs(vector<int>& answer, int node) {
        check[node] = true;
        answer.push_back(node);
        for (auto next_node : adjlist[node]) {
            order[next_node] -= 1;
            if (order[next_node] == 0 && check[node] == false) {
                dfs(answer, node);
            }
        } 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int index = 0; index < prerequisites.size(); index++) {
            int first_node = prerequisites[index][0];
            int second_node = prerequisites[index][1];

            adjlist[second_node].push_back(first_node); 
            order[first_node] += 1;
        }

        vector<int> answer;
        while (true) {
            bool have_new = false;
            for (int node = 0; node < numCourses; node++) {
                if (order[node] == 0 && check[node] == false) {have_new = true; dfs(answer, node);}
            }
            if (!have_new) {break;}
        }
        return (answer.size() == numCourses ? answer : vector<int>());
    }
};
