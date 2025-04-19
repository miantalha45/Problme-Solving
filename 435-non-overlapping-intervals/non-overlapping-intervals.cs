public class Solution {
    public int EraseOverlapIntervals(int[][] intervals) {
        int IntervalsToRemove = 0;

        Array.Sort(intervals, (a, b) => a[0].CompareTo(b[0]));
        Array.Sort(intervals, (a, b) => a[1].CompareTo(b[1]));
        int end = intervals[0][1];

        for(int i = 1; i < intervals.Length; i++)
        {
            if(intervals[i][0] < end)
            {
                IntervalsToRemove++;
            }
            else{
            end = intervals[i][1];

            }
        }
        return IntervalsToRemove;
    }
}