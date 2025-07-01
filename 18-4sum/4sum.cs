public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
        Array.Sort(nums);

        int n = nums.Length;
        IList<IList<int>> res = new List<IList<int>>();
        for(int a = 0;a < n;a++)
        {
            if(a > 0 && nums[a] == nums[a - 1])
                continue;
            
            for(int b = a + 1;b < n;b++)
            {
                if(b > a + 1 && nums[b] == nums[b - 1])
                  continue;
                
                int c = b + 1, d = n - 1;
                while(c < d)
                {
                    long sum = (long)nums[a] + nums[b] + nums[c] + nums[d];
                    if(sum > target)
                    {
                        d--;
                    }
                    else if(sum < target)
                    {
                        c++;
                    }
                    else
                    {
                        res.Add(new int[]{nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;
                        while(c < d && nums[c] == nums[c - 1])  c++;
                        while(c < d && nums[d] == nums[d + 1])  d--;
                    }
                }
            }
        }

        return res;
    }
}