class Solution {
public:
    map<pair<int, int>, int> map;
    int uniquePaths(int m, int n) {
        return helper(m, n, 0, 0);
    }

    int helper(int m, int n, int i, int j) {
        if(i >= m || j >= n) return 0;
        if(i==m-1 && j==n-1) return 1;

        if(map.count({i, j}))   return map[{i, j}];

        int rightCount = helper(m, n, i, j+1);
        int downCount = helper(m, n, i+1, j);

        return map[{i,j}] = rightCount + downCount;
    }
};