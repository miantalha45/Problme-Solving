public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        int n = nums.Length;

        int[] res = new int[n];
        res[n - 1] = 1;

        for(int i = n - 2;i >= 0;i--)
        {
            res[i] = res[i + 1] * nums[i + 1];
        }

        int leftSum = 1;
        for(int k = 0;k < n;k++)
        {
            res[k] = res[k] * leftSum;
            leftSum *= nums[k];
        }

        return res;
    }
}