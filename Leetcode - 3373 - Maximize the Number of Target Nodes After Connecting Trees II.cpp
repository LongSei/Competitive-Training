class Solution {
public:
    const int MAX_INT = 100000;
    int is_visited[100005];
    vector<int> adjlist[100005];

    void reset_visit_state() {
        for (int i = 0; i <= MAX_INT; i++) {
            is_visited[i] = false;
        }
    }

    void reset_adjlist_state() {
        for (int i = 0; i <= MAX_INT; i++) {
            adjlist[i].clear();
        }
    }

    void prepare_adjlist(vector<vector<int>>& edges) {
        for (vector<int>& edge : edges) {
            int start_node = edge[0];
            int end_node = edge[1];
            adjlist[start_node].push_back(end_node);
            adjlist[end_node].push_back(start_node);
        }
    }

    // Variable for 2 trees
    int subtree[2][100005][2]; // 1: odd, 0: even 
    int ancestor[2][100005][2];

    void dfs_subtree(int node, int tree_mask) {
        is_visited[node] = true;
        int even = 1; // Include Node
        int odd = 0;
        for (int next_node : adjlist[node]) {
            if (!is_visited[next_node]) {
                dfs_subtree(next_node, tree_mask);
            }
            even += subtree[tree_mask][next_node][1];
            odd += subtree[tree_mask][next_node][0];
        }
        subtree[tree_mask][node][1] = odd;
        subtree[tree_mask][node][0] = even;
    }

    void dfs_ancestor(int node, int tree_mask, int start_node) {
        is_visited[node] = true;

        if (node == start_node) {
            ancestor[tree_mask][node][0] = 1;
        }

        for (int next_node : adjlist[node]) {
            if (!is_visited[next_node]) {
                // Go to node with odd distance
                int odd_ancestor_as_parent_subtree = subtree[tree_mask][node][0] - subtree[tree_mask][next_node][1]; 
                // Go to node with even distance
                int even_ancestor_as_parent_subtree = subtree[tree_mask][node][1] - subtree[tree_mask][next_node][0]; 
                
                // Go to node with odd distance
                int odd_ancestor_as_parent_ancestor = ancestor[tree_mask][node][0]; 
                // Go to node with even distance
                int even_ancestor_as_parent_ancestor = ancestor[tree_mask][node][1]; 

                ancestor[tree_mask][next_node][1] = odd_ancestor_as_parent_subtree + odd_ancestor_as_parent_ancestor - 1;
                ancestor[tree_mask][next_node][0] = even_ancestor_as_parent_subtree + even_ancestor_as_parent_ancestor + 1;
                dfs_ancestor(next_node, tree_mask, start_node);
            }
        }
    }

    int amount_odd_tree(int node, int tree_mask) {
        return ancestor[tree_mask][node][1] + subtree[tree_mask][node][1];
    }
    
    int amount_even_tree(int node, int tree_mask) {
        return ancestor[tree_mask][node][0] + subtree[tree_mask][node][0] - 1;
    }

    void process_second_tree(vector<vector<int>>& edges) {
        reset_visit_state();
        reset_adjlist_state();
        prepare_adjlist(edges);
        int m = edges.size() + 1;
        int start_node = 0;
        for (int node = 0; node < m; node++) {
            if (adjlist[node].size() == 1) {
                start_node = node;
                break;
            }
        }
        dfs_subtree(start_node, 1);
        reset_visit_state();
        dfs_ancestor(start_node, 1, start_node);
    }

    void process_first_tree(vector<vector<int>>& edges) {
        reset_visit_state();
        reset_adjlist_state();
        prepare_adjlist(edges);
        int n = edges.size() + 1;
        int start_node = 0;
        for (int node = 0; node < n; node++) {
            if (adjlist[node].size() == 1) {
                start_node = node;
                break;
            }
        }
        dfs_subtree(start_node, 0);
        reset_visit_state();
        dfs_ancestor(start_node, 0, start_node);
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        process_second_tree(edges2);
        process_first_tree(edges1);

        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        int max_odd = 0; 
        int max_even = 0;

        for (int node = 0; node < m; node++) {
            max_odd = max(max_odd, amount_odd_tree(node, 1));
            max_even = max(max_even, amount_even_tree(node, 1));
        }
        vector<int> result; 
        for (int node = 0; node < n; node++) {
            int total_target = amount_even_tree(node, 0) + max(max_odd, max_even);
            result.push_back(total_target);
        }
        
        return result;
    }
};