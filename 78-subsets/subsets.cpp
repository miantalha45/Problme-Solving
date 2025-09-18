class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    if(index == nums.size()) {
        result.push_back(current);
        return;
    }
    
    // Branch 1: Include current element
    current.push_back(nums[index]);
    backtrack(nums, index + 1, current, result);
    current.pop_back(); // backtrack
    
    // Branch 2: Exclude current element  
    backtrack(nums, index + 1, current, result);
}
};