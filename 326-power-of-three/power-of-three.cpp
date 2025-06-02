class Solution {
public:
    bool isPowerOfThree(int n) {
        long x = 1;
        while(x < n)
        {
            x *= 3;
        }
        return x == n;
    }
};