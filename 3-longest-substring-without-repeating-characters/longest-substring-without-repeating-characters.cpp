class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_set<char> set;

        int l = 0;
        for(int r = 0;r < s.size(); r++)
        {
            while(set.count(s[r]) > 0)
            {
                set.erase(s[l]);
                l++;
            }
            
            set.insert(s[r]);
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            
        }

        return maxLen;
    }
};