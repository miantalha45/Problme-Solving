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
    public void ReorderList(ListNode head) {
        Stack<ListNode> stack = new();

        ListNode fast = head;
        ListNode slow = head;
        while(fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode temp = slow.next;
        slow.next = null;
        while(temp != null)
        {
            stack.Push(temp);
            temp = temp.next;
        }

        ListNode p = head;
        ListNode next = null;
        while(stack.Count > 0)
        {
            next = p.next;
            p.next = stack.Pop();
            p = p.next;
            p.next = next;
            p = p.next;
        }
    }
}