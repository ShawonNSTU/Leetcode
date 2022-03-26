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
    private List<int> BFS(TreeNode root) {
        List<int> res = new List<int>();
        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        while(q.Count > 0) {
            int n = q.Count;
            PriorityQueue<int, long> pq = new PriorityQueue<int, long>();
            for(int i = 0; i < n; ++i) {
                TreeNode currNode = q.Dequeue();
                pq.Enqueue(currNode.val, (long)-1 * currNode.val);
                if(currNode.left != null) q.Enqueue(currNode.left);
                if(currNode.right != null) q.Enqueue(currNode.right);
            }
            if(pq.Count > 0) res.Add(pq.Dequeue());
        }
        return res;
    } 
    public IList<int> LargestValues(TreeNode root) {
        return root == null ? new List<int>() : BFS(root);
    }
}