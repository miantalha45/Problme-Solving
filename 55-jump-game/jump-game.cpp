class Solution {
private:
    bool traverse(vector<int>& nums, int index, vector<int>& dp){
        if(index >= nums.size()) {
            return false;
        }

        if(index == nums.size() - 1) {
            dp[index] = 1;
            return true;
        }

        if(dp[index] != -1) {
            return dp[index] == 1 ? true : false;
        }

        for(int i = nums[index]; i > 0; i--) {
            if(traverse(nums, index + i, dp)) {
                return true;
            }
        }
        dp[index] = 0;
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return traverse(nums, 0, dp);
    }
};