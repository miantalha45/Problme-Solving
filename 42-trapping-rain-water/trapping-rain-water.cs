public class Solution {
    public int Trap(int[] height) {
        int n = height.Length;
        if(n == 0) return 0; 
        int left = 0, right = n - 1;
        int maxLeft = height[0], maxRight = height[n - 1];
        int res = 0;
        while(left < right)
        {
            int water = 0;
            if(maxRight < maxLeft)
            {
                water = maxRight - height[right];
            }
            else{
                water = maxLeft - height[left];
            }
            if(water > 0)
                res += water;
            if(maxLeft < height[left])
                maxLeft = height[left];
            if(maxRight < height[right])
                maxRight = height[right];
            if(maxRight < maxLeft)
            {
                right--;
            }
            else{
                left++;
            }
        }

        return res;
    }
}