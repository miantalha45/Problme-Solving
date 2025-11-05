class Solution {
public:

    void dfs(vector<vector<int>>& heights, int x, int y,
             vector<vector<bool>>& visited, int n, int m) {

        visited[x][y] = true;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                !visited[newX][newY] && heights[newX][newY] >= heights[x][y]) {
                dfs(heights, newX, newY, visited, n, m);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> result;
        vector<vector<bool>> pacificVisited(n, vector<bool>(m, false));
        vector<vector<bool>> atlanticVisited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
            dfs(heights, i, 0, pacificVisited, n, m);
        for (int j = 0; j < m; j++)
            dfs(heights, 0, j, pacificVisited, n, m);

        for (int i = 0; i < n; i++)
            dfs(heights, i, m - 1, atlanticVisited, n, m);
        for (int j = 0; j < m; j++)
            dfs(heights, n - 1, j, atlanticVisited, n, m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};