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
        ListNode dummy = new ListNode(0);
        ListNode res = dummy;
        while(head != null) {
            ListNode curr = head;
            int cnt = 0;
            while(head != null && head.val == curr.val) {
                ++cnt;
                head = head.next;
            }
            if(cnt == 1) {
                res.next = curr;
                res = res.next;
            }
        }
        res.next = null;
        return dummy.next;
    }
}