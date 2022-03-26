// Solution 1 (DFS):
class Solution {
    private int DFS(TreeNode node) {
        if(node == null) return 0;
        return 1 + Math.max(DFS(node.left), DFS(node.right));
    }
    public int maxDepth(TreeNode root) {
        return DFS(root);
    }
}

// Solution 2 (BFS):
class Solution {
    private int BFS(TreeNode root) {
        
        if(root == null) return 0;
        
        Queue<TreeNode> q1 = new LinkedList<>();
        q1.add(root);
        
        int level = 0;
        while(q1.size() > 0) {
            Queue<TreeNode> q2 = new LinkedList<>();
            while(q1.size() > 0) {
                TreeNode node = q1.remove();
                if(node.left != null) q2.add(node.left);
                if(node.right != null) q2.add(node.right);
            }
            ++level;
            q1 = q2;
        }
        
        return level;
    }
    public int maxDepth(TreeNode root) {
        return BFS(root);
    }
}
