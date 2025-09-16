class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& available, vector<int>& current,
                   vector<vector<int>>& result) {
        if (available.size() == 0) {
            result.push_back(current);
            return;
        }

        // Try each available number
        for (int i = 0; i < available.size(); i++) {
            int chosen = available[i];

            // Make choice
            current.push_back(chosen);
            available.erase(available.begin() + i); // Remove from available

            // Recurse
            backtrack(available, current, result);

            // Backtrack (REVERSE order!)
            available.insert(available.begin() + i,
                             chosen); // Restore to same position
            current.pop_back();       // Remove from current
        }
    }
};