class Solution {
public:
    unordered_map<int, int> map;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return helper(obstacleGrid, 0, 0);
    }
    int helper(vector<vector<int>>& obstacleGrid, int i, int j) {
        if(i >= obstacleGrid.size() || j >= obstacleGrid[0].size() || obstacleGrid[i][j] == 1) {
            return 0;
        }

        if(i==obstacleGrid.size()-1 && j == obstacleGrid[0].size() -1){
            return 1;
        }

        int key = i * 100 + j;
        if(map.count(key) > 0) return map[key];

        int rightCount = helper(obstacleGrid, i, j+1);
        int downCount = helper(obstacleGrid, i+1, j);

        return map[key] = rightCount + downCount;
    }
};