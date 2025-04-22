class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int len = nums.size();
        int slow = 0;
        int fast = slow + n;
        vector<int> res(len);
        int i = 0;
        while(slow < n)
        {
            res[i++] = nums[slow];
            res[i++] = nums[fast];
            slow += 1;
            fast += 1;
        }
        return res;
    }
};