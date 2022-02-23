/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

// BFS Solution
class Solution {
    private Node BFS(Node node) {
        HashMap<Node, Node> hMap = new HashMap<>();
        Queue<Node> q = new LinkedList<>();
        if(node != null) {
            hMap.put(node, new Node(node.val));
            q.add(node);
        }
        while(!q.isEmpty()) {
            Node currNode = q.remove();
            for(Node adj : currNode.neighbors) {
                if(!hMap.containsKey(adj)) {
                    hMap.put(adj, new Node(adj.val));
                    q.add(adj);
                }
                hMap.get(currNode).neighbors.add(hMap.get(adj));
            }
        }
        return hMap.get(node);
    }
    public Node cloneGraph(Node node) {
        return BFS(node);
    }
}

// DFS Solution
class Solution {
    private HashMap<Node, Node> hMap = new HashMap<>();
    private Node DFS(Node currNode) {
        if(currNode == null) return currNode;
        if(hMap.containsKey(currNode)) return hMap.get(currNode);
        hMap.put(currNode, new Node(currNode.val));
        for(Node adj : currNode.neighbors) {
            hMap.get(currNode).neighbors.add(DFS(adj));
        }
        return hMap.get(currNode);
    }
    public Node cloneGraph(Node node) {
        return DFS(node);
    }
}