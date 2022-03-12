/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        HashMap<Node, Node> hMap = new HashMap<>();
        hMap.put(null, null);
        Node temp = head;
        while(temp != null) {
            hMap.put(temp, new Node(temp.val));
            temp = temp.next;
        }
        temp = head;
        while(temp != null) {
            Node copyNode = hMap.get(temp);
            copyNode.next = hMap.get(temp.next);
            copyNode.random = hMap.get(temp.random);
            temp = temp.next;
        }
        return hMap.get(head);
    }
}