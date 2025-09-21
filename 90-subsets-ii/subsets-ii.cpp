class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int index, vector<int>& current,
                   vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        current.push_back(nums[index]);

        backtrack(nums, index + 1, current, result);
        current.pop_back();
        
        index++;
        while (index > 0 && index < nums.size() &&
               nums[index - 1] == nums[index]) {
            index++;
        }
        if (index > nums.size()) {
            return;
        }
        
        backtrack(nums, index, current, result);
    }
};