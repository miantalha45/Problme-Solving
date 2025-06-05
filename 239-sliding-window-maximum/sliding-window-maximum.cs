public class Solution {
    public int[] MaxSlidingWindow(int[] nums, int k) {
        List<int> res = new List<int>();
        LinkedList<int> q = new LinkedList<int>();

        int l = 0, r = 0;
        while(r < nums.Length)
        {
            while(q.Count > 0 && nums[q.Last.Value] < nums[r])
            {
                q.RemoveLast();
            }

            q.AddLast(r);

            if(q.First.Value < l)
            {
                q.RemoveFirst();
            }

            if((r - l + 1) >= k)
            {
                res.Add(nums[q.First.Value]);
                l += 1;
            }
            r += 1;

        }

        return res.ToArray();
    }
}