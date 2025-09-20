class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        backtrack(candidates, 0, current, target, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int index, vector<int>& current, int target, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0 || index >= candidates.size()) {
            return;
        }

        current.push_back(candidates[index]);
        backtrack(candidates, index, current, target - candidates[index], result);
        current.pop_back();

        backtrack(candidates, index + 1, current, target, result);
    }
};