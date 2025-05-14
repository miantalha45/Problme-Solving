class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        while(left < right)
        {
            int water = (right - left) * min(height[left], height[right]);
            if(height[left] < height[right])
            {
                left++;
            }
            else{
                right--;
            }

            if(water > maxWater)
            {
                maxWater = water;
            }
        }

        return maxWater;
    }
};