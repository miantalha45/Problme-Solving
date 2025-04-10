public class Solution {
    public int MaxEvents(int[][] events) {
        Array.Sort(events, (a, b) => a[0].CompareTo(b[0]));

        var minHeap = new PriorityQueue<int, int>(); 
        int day = 0, i = 0, res = 0, n = events.Length;

        while(i < n || minHeap.Count > 0)
        {
            if(minHeap.Count == 0)
            {
                day = events[i][0];
            }

            while(i < n && events[i][0] <= day)
            {
                minHeap.Enqueue(events[i][1], events[i][1]);
                i++;
            }

            while(minHeap.Count > 0 && minHeap.Peek() < day)
            {
                minHeap.Dequeue();

            }

            if(minHeap.Count > 0)
            {
                minHeap.Dequeue();
                res++;
                day++;
            }
        }

        return res;
    }
}