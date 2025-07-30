class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size();

        int pivot = INT_MAX;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            
            if(nums[mid] > nums[left])
            {
                pivot = min(pivot, nums[left]);
                left = mid + 1;
            }
            else
            {
                pivot = min(pivot, nums[mid]);
                right = mid;
            }
        }

        return pivot;
    }
};