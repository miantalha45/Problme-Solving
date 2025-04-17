class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res(nums.size());
        int i = 1;
        res[0] = nums[0];
        while(i < nums.size())
        {
            res[i] = nums[i] + res[i - 1];
            i++;
        }
        return res;
    }
};