/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

// O(N) Space
public class Solution {
    public ListNode detectCycle(ListNode head) {
        HashMap<ListNode, Boolean> hMap = new HashMap<>();
        ListNode temp = head;
        while(temp != null) {
            if(hMap.containsKey(temp)) return temp;
            hMap.put(temp, true);
            temp = temp.next;
        }
        return null;
    }
}

// O(1) Space
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head, fast = head;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow.next;
                    fast = fast.next;
                }
                return slow;
            }
        }
        return null;
    }
}