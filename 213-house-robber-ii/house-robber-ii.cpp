class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        
        int scen1 = robRange(nums, 0, n - 1);
        int scen2 = robRange(nums, 1, n);

        return max(scen1, scen2);
    }

private:
    int robRange(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = start; i < end; i++) {
            int allSum = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = allSum;
        }

        return prev1;
    }
};