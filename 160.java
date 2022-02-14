/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        ListNode l1 = headA, l2 = headB;
        
        while(l1.next != l2.next) {
            l1 = (l1.next == null) ? headB : l1.next;
            l2 = (l2.next == null) ? headA : l2.next;
        }
        
        return (l1 != l2) ? l1.next : l1;
    }
}
