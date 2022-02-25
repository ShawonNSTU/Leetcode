/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

// DFS: O(1) Space
class Solution {
    private Node DFS(Node root) {
        if(root == null) return root;
        if(root.left != null) root.left.next = root.right;
        if(root.next != null && root.next.left != null) root.right.next = root.next.left;
        DFS(root.left);
        DFS(root.right);
        return root;
    }
    public Node connect(Node root) {
        return DFS(root);
    }
}

// Level-Order-Traversal: O(1) Space
class Solution {
    private Node BFS(Node root) {
        Node level = root, levelT;
        while(level != null && level.left != null) {
            levelT = level;
            while(levelT != null) {
                levelT.left.next = levelT.right;
                if(levelT.next != null) levelT.right.next = levelT.next.left;
                levelT = levelT.next;
            }
            level = level.left;
        }
        return root;
    }
    public Node connect(Node root) {
        return BFS(root);
    }
}