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
    private int cnt = 0;
    private void DFS(TreeNode root, int currMax) {
        if(root == null) return;
        DFS(root.left, Math.max(currMax, root.val));
        DFS(root.right, Math.max(currMax, root.val));
        if(root.val >= currMax) ++cnt;
    }
    public int goodNodes(TreeNode root) {
        DFS(root, -10001);
        return cnt;
    }
}