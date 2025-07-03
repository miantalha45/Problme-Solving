public class Solution {
    public double FindMaxAverage(int[] nums, int k) {
        int n = nums.Length;
        double res = int.MinValue;
        double window = 0;

        int left = 0;
        for(int right = 0; right < n; right++)
        {
            window += nums[right];
            if(right - left + 1 > k)
            {
                window -= nums[left];
                left++;
            }
            if (right - left + 1 == k) {
                res = Math.Max(res, window / k);
            }
                
        }

        return res;
    }
}