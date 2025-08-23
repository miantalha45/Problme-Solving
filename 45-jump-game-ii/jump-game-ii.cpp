class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;

        int jumps = 0;
        int maxJump = 0;
        int currEnd = 0;
        
        for(int i = 0;i < n;i++)
        {
            maxJump = max(maxJump, i + nums[i]);

            if(i == currEnd)
            {
                ++jumps;
                currEnd = maxJump;
                if(currEnd >= n - 1)
                {
                    break;
                }
            }
        }
        return jumps;
    }
};