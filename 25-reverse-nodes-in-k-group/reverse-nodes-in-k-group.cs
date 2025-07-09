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
    public ListNode ReverseKGroup(ListNode head, int k) {
        ListNode prevTail = null;
        ListNode nextHead = null;

        ListNode slow = head;
        ListNode fast = head;

        for(int i = 0;i < k;i++)
        {
            if(fast != null)
            {
                fast = fast.next;
            }
            else
            {
                return head;
            }
        }

        nextHead = fast;

        while(true)
        {
            ListNode temp = slow;
            ListNode next = null;
            ListNode prev = null;
            while(temp != fast)
            {
                next = temp.next;
                temp.next = prev;
                prev = temp;
                temp = next;
            }

            if(prevTail != null)
            {
                prevTail.next = prev;
            }
            else
            {
                head = prev;
            }
            prevTail = slow;
            slow.next = nextHead;
            slow = slow.next;
            for(int i = 0;i < k;i++)
            {
                if(fast != null)
                {
                    fast = fast.next;
                }
                else
                {
                    return head;
                }
            }

            nextHead = fast;
        }

        return head;
    }
}