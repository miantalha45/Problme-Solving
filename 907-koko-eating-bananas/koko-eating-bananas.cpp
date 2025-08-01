class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int left = 1;int right = *max_element(piles.begin(), piles.end());
        int minTime = INT_MAX;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            double curTime = 0;
            for(int pile : piles)
            {
                curTime += ceil((double)pile / mid);
            }
            if(curTime <= h)
            {
                minTime = min(mid, minTime);
            }

            if(curTime <= h)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return minTime;
    }
};