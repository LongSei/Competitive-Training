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
    public boolean dfs(TreeNode a, TreeNode b) {
        if (a.val != b.val) {
            return false;
        }
        boolean result = true; 
        if (a.left != null && b.left != null) {
            result = dfs(a.left, b.left);
        } else if (a.left == null && b.left == null) {
            result = true;
        } else {
            result = false;
        }

        if (a.right != null && b.right != null) {
            result &= dfs(a.right, b.right);
        } else if (a.right == null && b.right == null) {
            result &= true; 
        } else {
            result &= false;
        }
        return result;
    }
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        } else if (p != null && q != null) {
            return dfs(p, q);
        } else {
            return false; 
        }
    }
}