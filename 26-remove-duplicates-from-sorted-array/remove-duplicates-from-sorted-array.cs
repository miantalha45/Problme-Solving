public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int n = nums.Length;

        if(n == 1)
            return 1;
        int i = 0, j = 1;
        int k = 0;
        while(j < n)
        {
            if(nums[i] == nums[j])
            {
                j++;
            }
            else
            {
                i++;
                nums[i] = nums[j];
            }
        }
        k = i + 1;
        
        return k;
    }
}