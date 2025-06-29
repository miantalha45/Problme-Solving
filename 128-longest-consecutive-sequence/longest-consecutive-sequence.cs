public class Solution {
    public int LongestConsecutive(int[] nums) {
        if(nums.Length == 0)
            return 0;
        
        HashSet<int> set = new HashSet<int>(nums);
        int res = 0;
        foreach(int n in set)
        {
            if(!set.Contains(n - 1))
            {
                int currNum = n;
                int currentStreak = 1;

                while(set.Contains(currNum + 1))
                {
                    currNum += 1;
                    currentStreak += 1;
                }
                res = Math.Max(res, currentStreak);
            }
        }

        return res;
    }
}