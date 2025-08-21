class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        // {capital, profit}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minCapital;

        priority_queue<int> maxProfit;

        for (int i = 0; i < capital.size(); i++) {
            minCapital.push({capital[i], profits[i]});
        }

        while (k > 0) {
            // Step 1: Move ALL affordable projects from minCapital to maxProfit
            while (!minCapital.empty() && minCapital.top().first <= w) {
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }

            // Step 2: If no profitable projects available, break
            if (maxProfit.empty())
                break;

            // Step 3: Take the most profitable project
            w += maxProfit.top();
            maxProfit.pop();
            k--;
        }

        return w;
    }
};