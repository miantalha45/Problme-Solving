public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        
        Array.Sort(nums);

        int n = nums.Length;
        IList<IList<int>> res = new List<IList<int>>();
        for(int i = 0;i < n;i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            int j = i + 1, k = n - 1;
            while(j < k)
            {
                int sum = nums[j] + nums[k];
                if(sum == target)
                {
                    res.Add(new int[]{nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < n && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while(k > j && nums[k] == nums[k + 1])
                        k--;
                }
                else if(sum > target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }

        return res;
    }
}