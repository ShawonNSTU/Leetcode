/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private int resCnt = 0;
    private void DFS(TreeNode root, int[] freq) {
        freq[root.val]++;
        if(root.left == null && root.right == null) {
            int oddCnt = 0;
            for(int i = 1; i < 10; ++i) {
                if(freq[i] % 2 == 1) ++oddCnt;
            }
            if(oddCnt <= 1) ++resCnt;
        }
        if(root.left != null) DFS(root.left, freq);
        if(root.right != null) DFS(root.right, freq);
        freq[root.val]--;
    }
    public int PseudoPalindromicPaths(TreeNode root) {
        DFS(root, new int[10]);
        return resCnt;
    }
}