class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        res[0] = 1;
        for(int i = 1; i < n; i++)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int rightSum = 1;
        for (int i = n - 1; i >= 0; i--) 
        {
            res[i] *= rightSum;
            rightSum *= nums[i];
        }

        return res;
    }
};