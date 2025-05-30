class Solution {
public:
    
    int fib(int n) {
        if(n <= 1)
            return n;
        int prev = 0;
        int prev1 = 0;
        int prev2 = 1;
        for(int i=1; i < n; i++)
        {
            prev = prev2 + prev1;
            prev1 = prev2;
            prev2 = prev;
        }
        return prev;
    }
};