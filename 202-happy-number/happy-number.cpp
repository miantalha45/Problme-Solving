class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;

        int slow = getnextNum(n);
        int fast = getnextNum(getnextNum(n));

        while(slow != fast) {
            if(fast == 1) {
                return true;
            }
            slow = getnextNum(slow);
            fast = getnextNum(getnextNum(fast));
        }

        if(slow == 1) {
            return true;
        }
        else{
            return false;
        }
    }

    int getnextNum(int n) {
        int output = 0;

        while(n > 0) {
            int digit = n % 10;
            output += digit * digit;

            n = n / 10;
        }

        return output;
    }
};