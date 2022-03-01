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

// Time Complexity: O(nlogk) -> k means total number of linked list
class Solution {
    private ListNode[] listPool;
    private ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode();
        ListNode temp = dummy;
        while(l1 != null && l2 != null) {
            if(l1.val < l2.val) {
                temp.next = l1;
                l1 = l1.next;
            }
            else {
                temp.next = l2;
                l2 = l2.next;
            }
            temp = temp.next;
        }
        if(l1 != null) temp.next = l1;
        else if(l2 != null) temp.next = l2;
        return dummy.next;
    }
    private ListNode mergeSort(int l, int r) {
        if(l < r) {
            int m = l + (r-l) / 2;
            ListNode left = mergeSort(l, m);
            ListNode right = mergeSort(m + 1, r);
            return merge(left, right);
        }
        else return listPool[l];
    }
    public ListNode mergeKLists(ListNode[] lists) {
        listPool = lists;
        int n = listPool.length - 1;
        return n < 0 ? null : mergeSort(0, n);
    }
}

// Time Complexity: O(n*k) -> k means total number of linked list
class Solution {
    private ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode();
        ListNode temp = dummy;
        while(l1 != null && l2 != null) {
            if(l1.val < l2.val) {
                temp.next = l1;
                l1 = l1.next;
            }
            else {
                temp.next = l2;
                l2 = l2.next;
            }
            temp = temp.next;
        }
        if(l1 != null) temp.next = l1;
        else if(l2 != null) temp.next = l2;
        return dummy.next;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        int n = lists.length;
        ListNode res = null;
        if(n > 0) res = lists[0];
        for(int i = 1; i < n; i++) {
            res = merge(res, lists[i]);
        }
        return res;
    }
}