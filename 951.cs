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
    Dictionary<int, KeyValuePair<int, int>> dict = new Dictionary<int, KeyValuePair<int, int>>();
    private bool DFS(TreeNode root, bool equivCheck) {
        TreeNode l = root.left, r = root.right;
        int lVal = -1, rVal = -1;
        bool lRet = true, rRet = true;
        if(l != null) {
            lVal = l.val;
            lRet = DFS(l, equivCheck);
        }
        if(r != null) {
            rVal = r.val;
            rRet = DFS(r, equivCheck);
        }
        if(equivCheck) {
            bool cRes = false;
            if(dict.ContainsKey(root.val)) {
                KeyValuePair<int, int> origin = dict[root.val];
                KeyValuePair<int, int> curr = new KeyValuePair<int, int>(lVal, rVal);
                cRes = (curr.Key == origin.Key && curr.Value == origin.Value) || (curr.Key == origin.Value && curr.Value == origin.Key);
            }
            return lRet & rRet & cRes;
        }
        else {
            dict.Add(root.val, new KeyValuePair<int, int>(lVal, rVal));
            return true;
        }
    }
    public bool FlipEquiv(TreeNode root1, TreeNode root2) {
        if(root1 == null && root2 == null) return true;
        else if(root1 == null && root2 != null) return false;
        else if(root1 != null && root2 == null) return false;
        else return DFS(root1, false) & DFS(root2, true);
    }
}