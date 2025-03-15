public class Solution {
    public int[][] Merge(int[][] intervals) {
        if(intervals.Length == 0) return new int[0][];

        Array.Sort(intervals, (a, b) => a[0].CompareTo(b[0]));

        List<int[]> merged = new List<int[]>();

        merged.Add(intervals[0]);
        foreach(var interval in intervals)
        {
           int[] last = merged.Last();

            if (interval[0] <= last[1]) {
                last[1] = Math.Max(last[1], interval[1]);
            } else {
                merged.Add(interval);
            }
        }

        return merged.ToArray();
    }
}