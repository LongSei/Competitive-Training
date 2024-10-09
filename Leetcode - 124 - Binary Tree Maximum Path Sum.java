/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    Map<TreeNode, Map<Integer, Integer>> dp = new HashMap<>();
    boolean checkPos = false;
    int maxValue = -10000000;
    public void dfs(TreeNode node) {
        if (node == null) return;
        if (node.val > 0) {
            checkPos = true;
        }
        maxValue = Math.max(maxValue, node.val);
        dp.putIfAbsent(node, new HashMap<>());
        dp.get(node).put(1, node.val);
        dp.get(node).put(2, node.val);
        if (node.left == null && node.right == null) {
            dp.get(node).put(0, 0);
            dp.get(node).put(1, node.val);
            dp.get(node).put(2, node.val);
            return;
        }

        if (node.left != null) {
            dfs(node.left);
            dp.putIfAbsent(node.left, new HashMap<>());
            dp.get(node).put(0, Math.max(dp.get(node.left).getOrDefault(0, 0),
                                         Math.max(dp.get(node.left).getOrDefault(1, 0),
                                                  dp.get(node.left).getOrDefault(2, 0))));
            dp.get(node).put(1, Math.max(dp.get(node).getOrDefault(1, 0),
                                         dp.get(node.left).getOrDefault(1, 0) + node.val));
        }

        if (node.right != null) {
            dfs(node.right);
            dp.putIfAbsent(node.right, new HashMap<>());
            dp.get(node).put(0, Math.max(dp.get(node).getOrDefault(0, 0),
                                         Math.max(dp.get(node.right).getOrDefault(0, 0),
                                                  Math.max(dp.get(node.right).getOrDefault(1, 0),
                                                           dp.get(node.right).getOrDefault(2, 0)))));
            dp.get(node).put(1, Math.max(dp.get(node).getOrDefault(1, 0),
                                         dp.get(node.right).getOrDefault(1, 0) + node.val));
        }

        if (node.left != null && node.right != null) {
            dp.get(node).put(2, Math.max(dp.get(node).getOrDefault(2, 0),
                                         dp.get(node.left).getOrDefault(1, 0) +
                                         dp.get(node.right).getOrDefault(1, 0) + node.val));
        }
    }

    public int maxPathSum(TreeNode root) {
        dfs(root);
        if (checkPos == false) {
            return maxValue;
        }
        return Math.max(dp.get(root).getOrDefault(0, 0),
                        Math.max(dp.get(root).getOrDefault(1, 0),
                                 dp.get(root).getOrDefault(2, 0)));
    }
}