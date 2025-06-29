public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        if(nums.Length == 1 || nums.Length == 0)
            return false;
        Array.Sort(nums);

        int l = 0, r = 1;
        while(r < nums.Length)
        {
            if(nums[l] == nums[r])
            {
                return true;
            }
            else
            {
                l++;
                r++;
            }
        }

        return false;
    }
}