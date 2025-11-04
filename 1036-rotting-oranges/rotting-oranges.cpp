class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int countOf1 = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    countOf1++;
                }
            }
        }

        int directions[4][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            int totalRotted = 0;
            for (int k = 0; k < size; k++) {
                auto top = q.front();
                int x = top.first;
                int y = top.second;
                for (int i = 0; i < 4; i++) {
                    int newX = x + directions[i][0];
                    int newY = y + directions[i][1];

                    if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                        if (grid[newX][newY] == 1) {
                            totalRotted++;
                            grid[newX][newY] = 2;
                            q.push({newX, newY});
                            countOf1--;
                        }
                    }
                }
                q.pop();
            }
            if(totalRotted > 0)
                time++;
        }

        return countOf1 == 0 ? time : -1;
    }
};