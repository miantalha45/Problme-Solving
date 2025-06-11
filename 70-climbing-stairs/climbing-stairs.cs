public class Solution {
    public int ClimbStairs(int n) {
        int[] memo = new int[n + 1];
        return Climb(memo, n);        
    }

    private int Climb(int[] dp, int n)
    {
        if(n<=2) return n;
        if(dp[n] != 0)
        {
            return dp[n];
        }

        dp[n] = Climb(dp, n - 1) + Climb(dp, n - 2);
        return dp[n];
    }
}