public class Solution {
    public int LongestConsecutive(int[] nums) {
        if(nums.Length == 0) return 0;
        int count = 0;
        
        HashSet<int> set = new HashSet<int>(nums);

        foreach(int n in set)
        {
            if(!set.Contains(n - 1))
            {
                int currentSteak = 1;
                int currentNum = n;
                while(set.Contains(currentNum + 1))
                {
                    currentSteak++;
                    currentNum++;
                }

                count = Math.Max(count, currentSteak);
            }
        }

        return count;
    }
}