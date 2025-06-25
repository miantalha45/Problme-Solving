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
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode p1 = l1;
        ListNode p2 = l2;

        ListNode dummy = new ListNode(0);
        ListNode sum = dummy;
        int carry = 0;

        while(p1 != null || p2 != null)
        {
            if(p1 != null && p2 != null)
            {
                int s = (p1.val + p2.val + carry);
                carry = s / 10;
                int digit = s % 10;
                sum.next = new ListNode(digit);
                sum = sum.next;
                p1 = p1.next;
                p2 = p2.next;
            }
            else if(p1 != null)
            {
                int s = (p1.val + carry);
                carry = s / 10;
                int digit = s % 10;
                sum.next = new ListNode(digit);
                sum = sum.next;
                p1 = p1.next;
            }
            else
            {
                int s = (p2.val + carry);
                carry = s / 10;
                int digit = s % 10;
                sum.next = new ListNode(digit);
                sum = sum.next;
                p2 = p2.next;
            }
        }

        if(carry > 0)
        {
            sum.next = new ListNode(carry);
            sum = sum.next;
        }

        return dummy.next;
    }
}