class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> memo1(n, -1);
        int scen1 = helper(0, n-1, nums, memo1);
        vector<int> memo2(n, -1);
        int scen2 = helper(1, n, nums, memo2);
        return max(scen1, scen2);
    }
private:
    int helper(int i, int end, vector<int>& nums, vector<int>& memo) {
        if(i >= end) {
            return 0;
        }

        if(memo[i] != -1) {
            return memo[i];
        }

        int robCurrent = nums[i] + helper(i + 2, end, nums, memo);
        int skipCurrent = helper(i + 1, end, nums, memo);

        return memo[i] = max(robCurrent, skipCurrent);
    }
};