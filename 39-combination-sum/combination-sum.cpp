class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backtrack(0, candidates, 0, target, path);
        return res;
    }

    void backtrack(int index, vector<int>& candidates, int total, int target, vector<int> path) {
        if(target == total) {
            res.push_back(path);
            return;
        }

        if(index == candidates.size() || target < total) {
            return;
        }

        path.push_back(candidates[index]);
        backtrack(index, candidates, total + candidates[index], target, path);

        path.pop_back();
        backtrack(index+1, candidates, total, target, path);
    }
};