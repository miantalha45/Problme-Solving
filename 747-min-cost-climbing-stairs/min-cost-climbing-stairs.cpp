class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int prev1 = cost[n-1];
        int prev2 = 0;

        for(int i = n - 2; i >= 0; i--) {
            int temp = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = temp;
        }

        return min(prev2, prev1);
    }
};