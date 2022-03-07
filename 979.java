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
    private int updateParentCoin(TreeNode currNode, TreeNode parentNode) {
        int cnt = 0;
        if(currNode.val < 1) {
            cnt += 1 - currNode.val;
            parentNode.val -= cnt;
        }
        else if(currNode.val > 1) {
            cnt += currNode.val - 1;
            parentNode.val += cnt;
        }
        return cnt;
    }
    private int DFS(TreeNode root) {
        int l = 0, r = 0, currMoveL = 0, currMoveR = 0;
        if(root.left != null) {
            l = DFS(root.left);
            currMoveL = updateParentCoin(root.left, root);
        }
        if(root.right != null) {
            r = DFS(root.right);
            currMoveR = updateParentCoin(root.right, root);
        }
        return l + r + currMoveL + currMoveR;
    }
    public int distributeCoins(TreeNode root) {
        return DFS(root);
    }
}