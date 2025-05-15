class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            int profit = prices[i] - lowPrice;
            lowPrice = min(lowPrice, prices[i]);
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};