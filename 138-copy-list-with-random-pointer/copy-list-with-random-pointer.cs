/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;
    
    public Node(int _val) {
        val = _val;
        next = null;
        random = null;
    }
}
*/

public class Solution {
    public Node CopyRandomList(Node head) {
        if(head == null) return head;

        Node current = head;
        while (current != null) {
            Node cloned = new Node(current.val);
            cloned.next = current.next;
            current.next = cloned;
            current = cloned.next;
        }

        current = head;
        while (current != null) {
            if (current.random != null) {
                current.next.random = current.random.next;
            }
            current = current.next.next;
        }

        current = head;
        Node pseudoHead = new Node(0);
        Node copyCurrent = pseudoHead;

        while (current != null) {
            Node cloned = current.next;
            copyCurrent.next = cloned;
            copyCurrent = cloned;

            current.next = cloned.next;
            current = current.next;
        }

        return pseudoHead.next;
    }
}