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
    public void debug(ListNode head) {
        ListNode temp = head;
        while (temp != null) {
            System.out.println(temp + " " + temp.val + " " + temp.next);
            temp = temp.next;
        }
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode current = head;
        ListNode subHead = null;
        ListNode subTail = null;
        int acc = 0;
        int cnt = 0;
        ListNode prevSubTail = null;
        if (k == 1) {
            return head;
        }
        while (current != null) {
            if (subHead == null || subTail == null) {
                subHead = current;
                subTail = current;
                acc += 1;
                current = current.next;
                continue;
            }

            acc += 1;
            ListNode next = current.next;
            subTail.next = next;

            current.next = subHead;
            subHead = current;

            current = next;

            if (prevSubTail != null) {
                prevSubTail.next = subHead;
            }

            if (acc == k) {
                cnt += 1;
                if (cnt == 1) head = subHead;
                prevSubTail = subTail;
                subHead = null; 
                subTail = null; 
                acc = 0;
            }
        }
        if (acc != 0) {
            ListNode temp = subHead; 
            ListNode prev = null;   

            while (temp != null) {
                ListNode next = temp.next; 
                temp.next = prev;          
                prev = temp;               
                temp = next;                
            }

            prevSubTail.next = prev;
        }
        return head;
    }
}