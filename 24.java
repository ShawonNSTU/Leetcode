/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy, curr = head;
        
        while(curr != null && curr.next != null) {
            ListNode l1 = curr.next;
            ListNode l2 = curr.next.next;
            
            l1.next = curr;
            curr.next = l2;
            prev.next = l1;
            
            prev = curr;
            curr = curr.next;
        }
        
        return dummy.next;
    }
}