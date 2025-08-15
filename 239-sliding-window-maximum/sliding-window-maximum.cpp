class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<int> q;
        int left = 0;
        for(int right = 0; right < n; right++)
        {
            while((right - left + 1) > k)
            {
                result.push_back(nums[q.front()]);
                if(!q.empty() && q.front() == left)
                {
                    q.pop_front();
                }
                left++;
            }

            if(q.empty())
            {
                q.push_back(right);
            }
            else
            {
                while(!q.empty() && nums[q.back()] < nums[right])
                {
                    q.pop_back();
                }
                q.push_back(right);
            }

        }
        result.push_back(nums[q.front()]);

        return result;
    }
};