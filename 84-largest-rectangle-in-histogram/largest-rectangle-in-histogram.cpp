class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int maxArea = 0;
        stack<int> s;

        for(int i = 0;i < n;i++)
        {
            while(!s.empty() && heights[i] < heights[s.top()])
            {
                int height = heights[s.top()];
                s.pop();

                int width = s.empty() ? i : (i - s.top() - 1);
                maxArea = max(maxArea, width * height);
            }

            s.push(i);
        }

        while(!s.empty())
        {
            int h = heights[s.top()];
            s.pop();
            
            int width = s.empty() ? n : (n - s.top() - 1);
            maxArea = max(maxArea, h * width);
        }

        return maxArea;
    }
};