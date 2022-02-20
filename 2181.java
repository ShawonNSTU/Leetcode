class Solution {
    
    private ListNode insert(ListNode root, int item) {
        ListNode temp = new ListNode();
        temp.val = item;
        temp.next = root;
        root = temp;
        return root;
    }
    
    private ListNode getLinkedList(List<Integer> arr, int n) {
        ListNode root = null;
        for(int i = n - 1; i >= 0 ; i--) root = insert(root, arr.get(i));
        return root;
    }
    
    public ListNode mergeNodes(ListNode head) {
        ListNode curr = head;
        int sum = 0;
        List<Integer> res = new ArrayList<>();
        while(curr != null) {
            if(curr.val == 0) {
                if(curr != head) {
                    res.add(sum);
                    sum = 0;
                }
            }
            else sum += curr.val;
            curr = curr.next;
        }
        ListNode resHead = getLinkedList(res, res.size());
        return resHead;
    }
}