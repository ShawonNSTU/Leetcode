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
    public ListNode rotateRight(ListNode head, int k) {
        ListNode tail = head;
        int len = 0;
        while(tail != null) {
            ++len;
            if(tail.next == null) break;
            tail = tail.next;
        }
        if(len > 0) k %= len;
        ListNode res = head;
        if(k > 0 && res != null) {
            ListNode temp = head;
            for(int i = 0; i < len-k-1; ++i) temp = temp.next;
            res = temp.next;
            temp.next = null;
            tail.next = head;
        }
        return res;
    }
}