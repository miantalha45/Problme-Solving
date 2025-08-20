class Solution {
public:
    struct Compare {
        bool operator()(const pair<long long, int>& a, const pair<long long, int>& b) {
            if (a.first != b.first) return a.first > b.first;  // Earlier end time has priority
            return a.second > b.second;  // Smaller room number has priority
        }
    };
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // sort the meetings
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;
        vector<int> count(n);

        for(int i = 0;i < n;i++)
        {
            available.push(i);
        }
        // min-heap: {end time, room number}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, Compare> used;
        for(auto& meeting : meetings)
        {
            long long start = meeting[0];
            long long end = meeting[1];
            while(!used.empty() && used.top().first <= start)
            {
                available.push(used.top().second);
                used.pop();
            }

            if (available.empty()) {
                auto current = used.top();
                used.pop();
                int room = current.second;
                long long newEnd = current.first + (end - start);
                used.push({newEnd, room});
                count[room]++;
                continue;
            }

            int assignedRoom = available.top();
            available.pop();
            used.push({end, assignedRoom});
            count[assignedRoom]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(count[i] > count[ans])   ans = i;
        }

        return ans;
    }
};