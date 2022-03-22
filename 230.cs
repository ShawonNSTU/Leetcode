// By Calculating Subtree Size
public class Solution {
    int[] lSubTree = new int[10001];
    private int SubTreeCount(TreeNode root) {
        if(root == null) return 0;
        lSubTree[root.val] = SubTreeCount(root.left);
        int r = SubTreeCount(root.right);
        return 1 + lSubTree[root.val] + r;
    }
    private int DFS(TreeNode root, int prevSum, int k) {
        if(lSubTree[root.val] + prevSum + 1 == k) return root.val;
        else if(lSubTree[root.val] + prevSum  + 1 > k) return DFS(root.left, prevSum, k);
        else return DFS(root.right, lSubTree[root.val] + prevSum + 1, k);
    }
    public int KthSmallest(TreeNode root, int k) {
        SubTreeCount(root);
        return DFS(root, 0, k);
    }
}

// Inorder Traverse
public class Solution {
    List<int> inorderSeq = new List<int>();
    private void DFS(TreeNode root) {
        if(root == null) return;
        DFS(root.left);
        inorderSeq.Add(root.val);
        DFS(root.right);
    }
    public int KthSmallest(TreeNode root, int k) {
        DFS(root);
        return inorderSeq.ElementAt(k-1);
    }
}