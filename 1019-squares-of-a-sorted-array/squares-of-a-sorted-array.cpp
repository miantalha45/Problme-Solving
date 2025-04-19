class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int left = 0, right = n - 1, index = n - 1;
    
        while(left <= right)
        {
            if(nums[left] * nums[left] > nums[right] * nums[right])
            {
                res[index] = nums[left] * nums[left];
                left++;
            }
            else{
                res[index] = nums[right] * nums[right];
                right--;
            }
            index--;
        }
        
        return res;
    }
};