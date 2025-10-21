class Solution {
public:
    unordered_map<int, int> map;
    int climbStairs(int n) {
        if(n == 2) return 2;
        if (n == 1)
            return 1;

        if(map.count(n) > 0)    return map[n];

        return map[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};