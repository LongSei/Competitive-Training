class Solution {
    private int computeRungsAdd(int current, int next, int dist) {
        if (next-current <= dist) {
            return 0;
        }
        if ((next - current) % dist == 0) {
            return ((next - current) / dist) - 1;
        }
        return ((next - current) / dist);
    }

    public int addRungs(int[] rungs, int dist) {
        int ans = computeRungsAdd(0, rungs[0], dist);
        for (int index = 0; index + 1 < rungs.length; index++) {
            ans += computeRungsAdd(rungs[index], rungs[index + 1], dist);
        }
        return ans;
    }
}
