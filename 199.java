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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if(root == null) return res;
        
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        res.add(root.val);
        
        while(!q.isEmpty()) {
            int n = q.size();
            int lValue = 101;
            while(n-- > 0) {
                TreeNode curr = q.remove();
                if(curr.left != null) {
                    q.add(curr.left);
                    lValue = curr.left.val;
                }
                if(curr.right != null) {
                    q.add(curr.right);
                    lValue = curr.right.val;
                }
            }
            if(lValue < 101) res.add(lValue);
        }
        
        return res;
    }
}