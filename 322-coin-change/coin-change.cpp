class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -2);
        return helper(coins, amount, memo);
    }

    int helper(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        if (memo[amount] != -2)
            return memo[amount];

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int result = helper(coins, amount - coin, memo);
            if (result != -1) {
                minCoins = min(minCoins, 1 + result);
            }
        }

        return memo[amount] = (minCoins == INT_MAX ? -1 : minCoins);
    }
};