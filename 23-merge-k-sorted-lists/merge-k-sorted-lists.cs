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
    public ListNode MergeKLists(ListNode[] lists) {
        int n = lists.Length;
        if(n == 0)
            return null;
        if(n == 1)
        {
            return lists[0];
        }
        for(int i = 1;i < n;i++)
        {
            lists[0] = MergerTwoLists(lists[0], lists[i]);
        }

        return lists[0];
    }

    private ListNode MergerTwoLists(ListNode l1, ListNode l2)
    {
        if(l1 == null)  return l2;
        if(l2 == null)  return l1;

        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;

        while(l1 != null && l2 != null)
        {
            if(l1.val < l2.val)
            {
                cur.next = l1;
                l1 = l1.next;
            }
            else
            {
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }

        if(l1 != null)
        {
            cur.next = l1;
        }

        if(l2 != null)
        {
            cur.next = l2;
        }

        return dummy.next;
    }
}