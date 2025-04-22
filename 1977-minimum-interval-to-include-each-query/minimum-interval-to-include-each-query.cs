public class Solution {
    public int[] MinInterval(int[][] intervals, int[] queries) {
        Array.Sort(intervals, (a, b) => a[0].CompareTo(b[0]));

        int n = queries.Length;
        int[][] sortedQueries = new int[n][];
        for (int i = 0; i < n; i++) {
            sortedQueries[i] = new int[] { queries[i], i };
        }

        Array.Sort(sortedQueries, (a, b) => a[0].CompareTo(b[0]));

        int[] res = new int[n];
        var pq = new PriorityQueue<int[],int>();
        int j = 0;

        foreach(var q in sortedQueries)
        {
            int index = q[1];
            int query = q[0];

            while(j < intervals.Length && intervals[j][0] <= query)
            {
                int end = intervals[j][1];
                int size = end - intervals[j][0] + 1;
                pq.Enqueue(new int[] {end, size} , size);
                j++;
            }

            while (pq.Count > 0 && pq.Peek()[0] < query) {
                pq.Dequeue();
            }

            res[index] = pq.Count > 0 ? pq.Peek()[1] : -1;
        }

        return res;

    }
}