class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right)
        {
            int mid = (left + right) / 2;

            if(nums[mid] == target)
                return true;
            
            while(left < mid && nums[left] == nums[mid])
                left++;

            while(right > mid && nums[right] == nums[mid])
                right--;
            
            if(nums[left] <= nums[mid])
            {
                if(target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(target <= nums[right] && target > nums[mid])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};