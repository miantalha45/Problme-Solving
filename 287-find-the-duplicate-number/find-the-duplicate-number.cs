public class Solution {
    public int FindDuplicate(int[] nums) {
        int n = nums.Length;

        for(int i = 0;i < n;i++)
        {
            if(nums[Math.Abs(nums[i]) - 1] < 0)
            {
                return Math.Abs(nums[i]);
            }
            nums[Math.Abs(nums[i]) - 1] *= -1;
        }

        return 0;
    }
}