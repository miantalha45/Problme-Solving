public class Solution {
    public int CountPairs(IList<int> nums, int target) {
        nums = nums.OrderBy(x => x).ToList();
        int n = nums.Count;
        int count = 0;

        int l = 0,r = n - 1;
        while(l < r)
        {
            if(nums[l] + nums[r] < target)
            {
                count += r - l;
                l++;
            }
            else
            {
                r--;
            }
        }

        return count;
    }
}