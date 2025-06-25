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

        Dictionary<Node, Node> map = new Dictionary<Node, Node>();
        Node newHead = new Node(head.val);
        map[head] = newHead;

        Node old = head.next;
        Node newTemp = newHead;

        while(old != null)
        {
            Node n = new Node(old.val);
            map[old] = n;
            newTemp.next = n;
            old = old.next;
            newTemp = newTemp.next;
        }

        old = head;
        newTemp =  newHead;

        while(old != null)
        {
            if(old.random == null)
            {
                newTemp.random = null;
            }
            else
            {
                if(map.ContainsKey(old.random))
                {
                    newTemp.random = map[old.random];
                }

            }
            old = old.next;
            newTemp = newTemp.next;
        }

        return newHead;
    }
}