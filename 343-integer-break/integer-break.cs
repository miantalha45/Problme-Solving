public class Solution {
    public int IntegerBreak(int n) {
        List<int> nums = new List<int>();
        int res = 1;
        int k = 0;
        while(n > 4)
        {
            nums.Add(3);
            n -= 3;
            k++;
        }
        nums.Add(n);
        if(nums.Count == 1)
        {
            if(nums[0] == 2)
            {
                nums.Clear();
                nums.Add(1);
                nums.Add(1);
            }
            else if(nums[0] == 3)
            {
                nums.Clear();
                nums.Add(1);
                nums.Add(2);
            }
            else if(nums[0] == 4)
            {
                nums.Clear();
                nums.Add(2);
                nums.Add(2);
            }
        }

        for(int i = 0; i < nums.Count; i++)
        {
            res *= nums[i];
        }

        return res;
    }
}