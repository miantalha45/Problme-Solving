public class Solution {
    public int Search(int[] nums, int target) {
        int n = nums.Length;
        int l = 0, r = n - 1;
        while(l <= r)
        {
            int m = (l + r) / 2;
            if(nums[m] == target)
            {
                return m;
            }
            if(nums[l] <= nums[m])
            {
                if(target > nums[m] || target < nums[l])
                {
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            else
            {
                if(target < nums[m] || target > nums[r])
                {
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
        }

        return -1;
    }
}