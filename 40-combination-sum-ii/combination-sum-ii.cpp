class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, current, target, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int index, vector<int>& current,
                   int target, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0 || index >= candidates.size()) {
            return;
        }

        current.push_back(candidates[index]);
        backtrack(candidates, index + 1, current, target - candidates[index],
                  result);

        current.pop_back();

        int nextIndex = index + 1;
        while (nextIndex < candidates.size() &&
               candidates[index] == candidates[nextIndex]) {
            nextIndex++;
        }
        backtrack(candidates, nextIndex, current, target, result);
    }
};