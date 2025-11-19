class Solution {
public:
    int traverse(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<int>>& dp) {
        if (i >= n || j >= m)
            return 1e9;

            if(dp[i][j] != -1) {
                return dp[i][j];
            }

        if (i == n - 1 && j == m - 1)
            return grid[i][j];

        return dp[i][j] = grid[i][j] + min(traverse(grid, i + 1, j, n, m, dp),
                                traverse(grid, i, j + 1, n, m, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return traverse(grid, 0, 0, n, m, dp);
    }
};