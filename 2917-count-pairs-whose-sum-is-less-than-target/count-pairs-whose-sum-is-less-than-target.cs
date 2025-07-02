public class Solution {
    public int CountPairs(IList<int> nums, int target) {
        int n = nums.Count;
        
        nums = nums.OrderBy(x => x).ToList();
        int count = 0;

        for(int i = 0;i < n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                if(nums[i] + nums[j] < target)
                {
                    count += 1;
                }
            }
        }

        return count;
    }
}