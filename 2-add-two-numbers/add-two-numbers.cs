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
        return Add(l1, l2, 0);
    }

    private ListNode Add(ListNode l1, ListNode l2, int carry)
    {
        if(l1 == null && l2 == null && carry == 0)
            return null;
        
        int val1 = l1?.val ?? 0;
        int val2 = l2?.val ?? 0;

        int sum = val1 + val2 + carry;
        int newDigit = sum % 10;
        int newCarry = sum / 10;

        ListNode node = new ListNode(newDigit);
        node.next = Add(l1?.next, l2?.next, newCarry);
        return node;
    }
}