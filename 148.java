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

 // Recursive Merge Sort: O(nlogn) Time & O(logn) Space
class Solution {
    private ListNode merge(ListNode left, ListNode right) {
        ListNode dummy = new ListNode();
        ListNode temp = dummy;
        while(left != null && right != null) {
            if(left.val < right.val) {
                temp.next = left;
                left = left.next;
            }
            else {
                temp.next = right;
                right = right.next;
            }
            temp = temp.next;
        }
        if(left != null) temp.next = left;
        if(right != null) temp.next = right;
        return dummy.next;
    }
    private ListNode getMiddleNode(ListNode head) {
        ListNode slow = head, fast = head;
        ListNode prev = null;
        while(fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        return prev;
    }
    private ListNode mergeSort(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode left = head;
        ListNode mid = getMiddleNode(head);
        ListNode right = mid.next;
        mid.next = null;
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left, right);
    }
    public ListNode sortList(ListNode head) {
        return mergeSort(head);
    }
}

// Iterative Merge Sort: O(nlogn) Time & O(1) Space
class Solution {
    private ListNode merge(ListNode left, ListNode right, ListNode res) {
        while(left != null && right != null) {
            if(left.val < right.val) {
                res.next = left;
                left = left.next;
            }
            else {
                res.next = right;
                right = right.next;
            }
            res = res.next;
        }
        if(left != null) res.next = left;
        if(right != null) res.next = right;
        while(res.next != null) res = res.next;
        return res;
    }
    private ListNode split(ListNode head, int cnt) {
        if(head == null) return head;
        for(int i = 1; i < cnt && head.next != null; i++) head = head.next;
        ListNode right = head.next;
        head.next = null;
        return right;
    }
    public ListNode sortList(ListNode head) {
        ListNode temp = head;
        int cnt = 0;
        while(temp != null) {
            ++cnt;
            temp = temp.next;
        }
        ListNode dummy = new ListNode();
        dummy.next = head;
        for(int i = 1; i < cnt; i *= 2) {
            ListNode res = dummy;
            ListNode curr = dummy.next;
            while(curr != null) {
                ListNode left = curr;
                ListNode right = split(left, i);
                curr = split(right, i);
                res = merge(left, right, res);
            }
        }
        return dummy.next;
    }
}