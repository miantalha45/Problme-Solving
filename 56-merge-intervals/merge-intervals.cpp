class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> list;
        
        sort(intervals.begin(), intervals.end());

        list.push_back(intervals[0]);

        for(const auto& interval : intervals)
        {
            vector<int>& last = list.back();
            if(interval[0] <= last[1])
            {
                last[1] = max(interval[1], last[1]);
            }
            else{
                list.push_back(interval);
            }
        }

        return list;
    }
};