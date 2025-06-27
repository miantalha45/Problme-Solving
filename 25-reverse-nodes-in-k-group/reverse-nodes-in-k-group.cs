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
        if(head == null) return  head;


        ListNode dummy = new ListNode(0, head);
        ListNode grpPrev = dummy;

        while(true)
        {
            ListNode kth = GetKth(grpPrev, k);
            if(kth == null)
            {
                break;
            }
            ListNode grpNext = kth.next;

            ListNode prev = kth.next;
            ListNode cur = grpPrev.next;
            while(cur != grpNext)
            {
                ListNode temp = cur.next;
                cur.next = prev;
                prev = cur;

                cur = temp;
            }

            ListNode tmpNode = grpPrev.next;
            grpPrev.next = kth;
            grpPrev = tmpNode;

        }


        return dummy.next;
    }

    private ListNode GetKth(ListNode cur, int k)
    {
        while(cur != null && k > 0)
        {
            cur = cur.next;
            k--;
        }

        return cur;
    }
}