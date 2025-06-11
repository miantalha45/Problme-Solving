public class Solution {
    public int MinCostClimbingStairs(int[] cost) {
        int n = cost.Length;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 0;
        
         for (int i = 2; i <= n; i++) {
            int oneStep = dp[i - 1] + cost[i - 1];
            int twoSteps = dp[i - 2] + cost[i - 2];
            dp[i] = Math.Min(oneStep, twoSteps);
        }

        return dp[n];
    }
}