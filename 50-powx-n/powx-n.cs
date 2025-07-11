public class Solution {
    public double MyPow(double x, int n) {
        long pow = (long)n;
        if(pow < 0) {
            pow = -pow;
            x = 1 / x;
        }
        if(pow == 0) return 1;
        
        double half = MyPow(x, (int)(pow / 2));
        if(pow % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
}