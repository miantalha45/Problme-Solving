public class BrowserHistory
{
    public class Node
    {
        public Node prev;
        public string val;
        public Node next;

        public Node(Node prev = null, string val = "", Node next = null)
        {
            this.prev = prev;
            this.val = val;
            this.next = next;
        }
    }

    private Node currentPage;

    public BrowserHistory(string homepage)
    {
        currentPage = new Node(null, homepage, null);
    }

    public void Visit(string url)
    {
        currentPage.next = null;

        Node newNode = new Node(currentPage, url, null);
        currentPage.next = newNode;
        currentPage = newNode;
    }

    public string Back(int steps)
    {
        while (steps > 0 && currentPage.prev != null)
        {
            currentPage = currentPage.prev;
            steps--;
        }
        return currentPage.val;
    }

    public string Forward(int steps)
    {
        while (steps > 0 && currentPage.next != null)
        {
            currentPage = currentPage.next;
            steps--;
        }
        return currentPage.val;
    }
}