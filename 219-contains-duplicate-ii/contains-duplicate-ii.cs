public class Solution {
    public bool ContainsNearbyDuplicate(int[] nums, int k) {
        int n = nums.Length;
        if(n == 1)
            return false;

        HashSet<int> set = new HashSet<int>();
        int i = 0;
        for(int j = 0;j < n; j++)
        {
            if(set.Contains(nums[j]))
            {
                return true;
            }
            set.Add(nums[j]);
            if(j - i + 1 > k)
            {
                set.Remove(nums[i]);
                i++;
            }
        }

        return false;
    }
}