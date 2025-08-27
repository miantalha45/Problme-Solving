class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        unordered_map<char, int> last;
        for(int i = 0;i < n;i++)
        {
            last[s[i]] = i;
        }

        vector<int> result;
        int currEnd = 0;
        int currStart = 0;
        for(int i = 0;i < n;i++)
        {
            currEnd = max(last[s[i]], currEnd);
            
            if(currEnd == i)
            {
                result.push_back(i - currStart + 1);
                currStart = i + 1;
            }
            
        }

        return result;
    }
};