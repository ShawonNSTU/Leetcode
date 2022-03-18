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
    public TreeNode ConstructFromPrePost(int[] preorder, int[] postorder) {
        Dictionary<int, TreeNode> dict = new Dictionary<int, TreeNode>();
        int n = preorder.Length;
        bool[] isRoot = new bool[n];
        int[] pos = new int[n + 1];
        for(int i = 0; i < n; ++i) {
            pos[postorder[i]] = i;
        }
        for(int i = 0; i < n; ++i) {
            int nextRoot = 0;
            for(int j = pos[preorder[i]] + 1; j < n; ++j) {
                if(isRoot[j]) {
                    nextRoot = postorder[j];
                    break;
                }
            }
            TreeNode node = new TreeNode(preorder[i], null, null);
            dict[preorder[i]] = node;
            if(nextRoot != 0) {
                TreeNode root = dict[nextRoot];
                if(root.left == null) root.left = node;
                else root.right = node;
            }
            isRoot[pos[preorder[i]]] = true;
        }
        return dict[preorder[0]];
    }
}