class Solution {
    private int[] component; 
    private int[] masked;
    private int maskCounter; 
    private int sizeComponent; 

    public int dfs(int[] edges, int node) {
        masked[node] = maskCounter;
        if (edges[node] == -1) {return -1;}
        if (masked[edges[node]] == masked[node]) {
            component[node] = edges[node]; 
            sizeComponent++;
        } else if (masked[edges[node]] == 0) {
            component[node] = dfs(edges, edges[node]);
            if (component[node] != -1) {
                sizeComponent++;
            } 
            if (component[node] == node) {
                return -1;
            }
        } else {
            return -1;
        }
        return component[node];
    }

    public int longestCycle(int[] edges) {
        int res = 0; 
        component = new int[edges.length + 1];
        for (int node = 0; node < edges.length; node++) {
            component[node] = -1;
        }
        masked = new int[edges.length + 1];
        maskCounter = 0; 
        sizeComponent = 0;

        for (int node = 0; node < edges.length; node++) {
            if (masked[node] != 0) {
                continue;
            }
            maskCounter++;
            sizeComponent = 0; 
            dfs(edges, node);
            if (sizeComponent != 0) {
                res = (res < sizeComponent ? sizeComponent : res);
            }
        }
        return (res == 0 ? -1 : res);
    }
}
