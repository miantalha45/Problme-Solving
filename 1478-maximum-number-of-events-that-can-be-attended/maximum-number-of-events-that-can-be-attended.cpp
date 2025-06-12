class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        set<int> set;
        for(int i = 1;i <= 100000;i++) set.insert(i);
        int count = 0;

        for (const vector<int>& event : events) {
            int start = event[0];
            int end = event[1];

            auto lb = set.lower_bound(start);
            if(lb == set.end() || *lb > end)
            {
                continue;
            }
            else
            {
                count++;
                set.erase(*lb);
            }
        }

        return count;
    }
};