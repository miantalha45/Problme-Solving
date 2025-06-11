public class Solution {
    public int ClimbStairs(int n) {
        if(n<=2) return n;
        int lastOne = 2;
        int lastTwo = 1;
        int allCount = 0;

        for(int i = 3;i <= n;i++)
        {
            allCount = lastTwo + lastOne;
            lastTwo = lastOne;
            lastOne = allCount;
        }

        return allCount;
    }
}