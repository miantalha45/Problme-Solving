class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(amount + 1, vector<int>(coins.size(), -1));
        return helper(amount, coins, 0, memo);
    }
    
    int helper(int amount, vector<int>& coins, int index, 
               vector<vector<int>>& memo) {
        if (amount == 0) return 1;
        if (amount < 0 || index >= coins.size()) return 0;
        
        if (memo[amount][index] != -1) return memo[amount][index];
        
        int include = helper(amount - coins[index], coins, index, memo);
        int exclude = helper(amount, coins, index + 1, memo);
        
        return memo[amount][index] = include + exclude;
    }
};