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

// BFS Approach
class Solution {
    public int sumEvenGrandparent(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int sum = 0;
        while(!q.isEmpty()) {
            int cnt = q.size();
            for(int i = 0; i < cnt; ++i) {
                TreeNode curr = q.remove();
                int currNum = curr.val & 1;
                if(curr.left != null) {
                    q.add(curr.left);
                    if(currNum != 1) {
                        if(curr.left.left != null) sum += curr.left.left.val;
                        if(curr.left.right != null) sum += curr.left.right.val;
                    }
                }
                if(curr.right != null) {
                    q.add(curr.right);
                    if(currNum != 1) {
                        if(curr.right.left != null) sum += curr.right.left.val;
                        if(curr.right.right != null) sum += curr.right.right.val;
                    }
                }
            }
        }
        return sum;
    }
}

// DFS Approach
class Solution {
    private int DFS(TreeNode root, int parent, int gParent) {
        if(root == null) return 0;
        int sum = DFS(root.left, root.val, parent) + DFS(root.right, root.val, parent);
        if(gParent > 0 && (gParent & 1) != 1) sum += root.val;
        return sum;
    }
    public int sumEvenGrandparent(TreeNode root) {
        return DFS(root, 0, 0);
    }
}
