class Solution {
public:
    int climbStairs(int n) {
        if (n == 2)
            return 2;
        if (n == 1)
            return 1;

        int prev1 = 2;
        int prev2 = 1;

        int currentStep = 0;

        for(int i = 3;i <= n; i++) {
            currentStep = prev1 + prev2;
            prev2 = prev1;
            prev1 = currentStep;
        }

        return currentStep;
    }
};