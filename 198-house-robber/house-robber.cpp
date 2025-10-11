class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return helper(0, nums, memo);
    }
    int helper(int i, vector<int>& nums, vector<int>& memo) {
        if(i >= nums.size())
            return 0;

        if(memo[i] != -1) {
            return memo[i];
        }
        int robCurrent = nums[i] + helper(i + 2, nums, memo);
        int skipCurrent = helper(i + 1, nums, memo);

        return memo[i] = max(robCurrent, skipCurrent);
    }
};