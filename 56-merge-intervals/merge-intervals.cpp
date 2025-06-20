class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int i = 1;
        while(i < n)
        {
            if(res.back()[1] >= intervals[i][0])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);;
            }
            else
            {
                res.push_back(intervals[i]);
            }
            i++;
        }

        return res;
    }
};