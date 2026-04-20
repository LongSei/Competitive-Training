class Solution {
    public int connectTwoGroups(List<List<Integer>> cost) { 
        int nGrOne = cost.size(); 
        int nGrTwo = cost.get(0).size(); 
        int maskState = (1 << nGrTwo);
        int INF = Integer.MAX_VALUE / 2;
        int[][] min_cost = new int[nGrOne + 1][maskState];
        for (int i = 0; i <= nGrOne; i++) {
            Arrays.fill(min_cost[i], INF);
        }

        min_cost[0][0] = 0;
        for (int oIndex = 1; oIndex <= nGrOne; oIndex++) {
            for (int fromState = 0; fromState < maskState; fromState++) {
                if (min_cost[oIndex - 1][fromState] == INF) continue;
                for (int tIndex = 0; tIndex < nGrTwo; tIndex++) {
                    int newState = fromState | (1 << tIndex);
                    min_cost[oIndex][newState] = Math.min(
                        min_cost[oIndex][newState],
                        min_cost[oIndex - 1][fromState] 
                        + cost.get(oIndex - 1).get(tIndex)
                    );
                }
            }
        }

        int[] minCost = new int[nGrTwo];
        Arrays.fill(minCost, INF);
        for (int tIndex = 0; tIndex < nGrTwo; tIndex++) {
            for (int oIndex = 0; oIndex < nGrOne; oIndex++) {
                minCost[tIndex] = Math.min(minCost[tIndex], cost.get(oIndex).get(tIndex));
            }
        }
        int res = INF;
        for (int state = 0; state < maskState; state++) {
            int extra = 0;
            for (int tIndex = 0; tIndex < nGrTwo; tIndex++) {
                if ((state & (1 << tIndex)) == 0) {
                    extra += minCost[tIndex];
                }
            }
            res = Math.min(res, min_cost[nGrOne][state] + extra);
        }

        return res;
    }
}
