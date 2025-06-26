public class LRUCache {
    private class Node {
        public Node prev;
        public int key;
        public int val;
        public Node next;
        
        public Node(int key, int val) {
            this.key = key;
            this.val = val;
            this.prev = null;
            this.next = null;
        }
    }
    
    private Dictionary<int, Node> map;
    private int capacity;
    private Node head;
    private Node tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new Dictionary<int, Node>();
        
        this.head = new Node(0, 0);
        this.tail = new Node(0, 0);
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }
    
    public int Get(int key) {
        if (map.ContainsKey(key)) {
            Node node = map[key];
            MoveToHead(node);
            return node.val;
        }
        return -1;
    }
    
    public void Put(int key, int value) {
        if (map.ContainsKey(key)) {
            Node node = map[key];
            node.val = value;
            MoveToHead(node);
        } else {
            Node newNode = new Node(key, value);
            
            if (map.Count >= capacity) {
                Node tail = RemoveTail();
                map.Remove(tail.key);
            }
            
            map[key] = newNode;
            AddToHead(newNode);
        }
    }
    
    private void AddToHead(Node node) {
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
    }
    
    private void RemoveNode(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    
    private void MoveToHead(Node node) {
        RemoveNode(node);
        AddToHead(node);
    }
    
    private Node RemoveTail() {
        Node lastNode = tail.prev;
        RemoveNode(lastNode);
        return lastNode;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */