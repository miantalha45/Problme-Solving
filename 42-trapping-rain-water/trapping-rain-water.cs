public class Solution {
    public int Trap(int[] height) {
        int n = height.Length;

        int[] prefixMax = new int[n];
        int[] suffixMax = new int[n];
        int currPre = 0;
        int currSuf = 0;
        
        int l = 0, r = n - 1;
        while(r >= 0 && l < n)
        {
            if(l == 0)
            {
                prefixMax[l] = 0;
                currPre = height[l];
            }
            else
            {
                prefixMax[l] = currPre;
                currPre = Math.Max(height[l], currPre);
            }

            if(r == n -1)
            {
                suffixMax[r] = 0;
                currSuf = height[r];
            }
            else
            {
                suffixMax[r] = currSuf;
                currSuf = Math.Max(height[r], currSuf);
            }

            l++;
            r--;
        }

        int res = 0;
        for(int i = 0;i < n;i++)
        {
            int storedWater = Math.Min(prefixMax[i], suffixMax[i]) - height[i];
            if(storedWater > 0)
            {
                res += storedWater;
            }
        }

        return res;
    }
}