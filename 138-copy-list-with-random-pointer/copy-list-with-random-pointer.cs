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
        if(head == null)
            return head;
        Dictionary<Node, Node> map = new();
        Node cur = head;
        while(cur != null)
        {
            map[cur] = new Node(cur.val);
            cur = cur.next;
        }

        cur = head;
        while(cur != null)
        {
            map[cur].next = cur.next == null ? null : map[cur.next];
            map[cur].random = cur.random == null ? null : map[cur.random];
            cur = cur.next;
        }

        return map[head];
    }
}