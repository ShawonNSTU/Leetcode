/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    private KeyValuePair<int, int> getSwapValue(ListNode temp, int k) {
        int num = 0, cnt = 0;
        while(temp != null) {
            ++cnt;
            if(cnt == k) num = temp.val;
            temp = temp.next;
        }
        return new KeyValuePair<int, int>(num, cnt);
    }
    public ListNode SwapNodes(ListNode head, int k) {
        KeyValuePair<int, int> l = getSwapValue(head, k);
        KeyValuePair<int, int> r = getSwapValue(head, l.Value - k + 1);
        ListNode dummy = new ListNode(0, head);
        int cnt = 0;
        while(head != null) {
            ++cnt;
            if(cnt == k) head.val = r.Key;
            if(cnt == l.Value - k + 1) head.val = l.Key;
            head = head.next;
        }
        return dummy.next;
    }
}