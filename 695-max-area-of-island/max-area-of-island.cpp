class Solution {
public:
    int result = 0;

    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i == n || j < 0 || j == m)
            return 0;
        if (grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        return 1 + dfs(grid, i + 1, j, m, n) + dfs(grid, i - 1, j, m, n) +
               dfs(grid, i, j + 1, m, n) + dfs(grid, i, j - 1, m, n);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    result = max(result, dfs(grid, i, j, m, n));
                }
            }
        }

        return result;
    }
};