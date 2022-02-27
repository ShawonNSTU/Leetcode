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
class Pair {
    TreeNode node;
    int idx;
    Pair(TreeNode node, int idx) {
        this.node = node;
        this.idx = idx;
    }
}
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        int maxWidth = 0;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, 0));
        while(!q.isEmpty()) {
            int n = q.size();
            int leftIdx = q.peek().idx;
            int currLevelWidth = 0;
            while(n-- > 0) {
                Pair p = q.remove();
                int currIdx = p.idx - leftIdx;
                currLevelWidth = Math.max(currLevelWidth, currIdx + 1);
                if(p.node.left != null) {
                    q.add(new Pair(p.node.left, 2*currIdx+1));
                }
                if(p.node.right != null) {
                    q.add(new Pair(p.node.right, 2*currIdx+2));
                }
            }
            maxWidth = Math.max(maxWidth, currLevelWidth);
        }
        return maxWidth;
    }
}