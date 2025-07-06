public class Solution {
    public int[] MaxSlidingWindow(int[] nums, int k) {
        int n = nums.Length;
        if(n == 1)
            return nums;

        List<int> res = new();
        LinkedList<int> q = new();

        int l = 0;
        for(int r = 0;r < n;r++)
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
                l++;
            }
        }

        return res.ToArray();
    }
}