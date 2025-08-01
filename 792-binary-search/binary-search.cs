public class Solution {
    public int Search(int[] nums, int target) {
        int n = nums.Length;

        int l = 0, r = n - 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return -1;
    }
}