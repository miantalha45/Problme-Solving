class Solution {
public:
    bool isPowerOfTwo(int n) {
        long x = 1;
        while(x < n)
        {
            x *= 2;
        }

        return x == n;
    }
};