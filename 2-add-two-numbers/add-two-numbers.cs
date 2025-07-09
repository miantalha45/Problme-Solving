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
        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;
        int carry = 0;
        while(l1 != null || l2 != null)
        {
            int rem = 0;
            if(l1 == null)
            {
                rem = (l2.val + carry) % 10;
                carry = (l2.val + carry) / 10;
                temp.next = new ListNode(rem);
                l2 = l2.next;
            }
            else if(l2 == null)
            {
                rem = (l1.val + carry) % 10;
                carry = (l1.val + carry) / 10;
                temp.next = new ListNode(rem);
                l1 = l1.next;
            }
            else
            {
                rem = (l1.val + l2.val + carry) % 10;
                carry = (l1.val + l2.val + carry) / 10;
                temp.next = new ListNode(rem);
                l1 = l1.next;
                l2 = l2.next;
            }
            temp = temp.next;
        }

        if(carry > 0)
        {
            temp.next = new ListNode(carry);
        }

        return dummy.next;
    }
}