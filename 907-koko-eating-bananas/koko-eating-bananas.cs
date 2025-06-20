public class Solution {
    public int MinEatingSpeed(int[] piles, int h) {
        int n = piles.Length;

        int l = 1, r = piles.Max();
        int res = r;
        while(l <= r)
        {
            int mid = (r + l) / 2;
            long sum = 0;
            foreach (int p in piles) {
                sum += (int)Math.Ceiling((double)p / mid);
            }
            if (sum <= h) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
}