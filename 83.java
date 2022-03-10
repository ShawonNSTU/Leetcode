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
    public ListNode deleteDuplicates(ListNode head) {
        if(head != null && head.next != null) {
            ListNode temp = deleteDuplicates(head.next);
            if(temp.val == head.val) head = temp;
            else head.next = temp;
        }
        return head;
    }
}