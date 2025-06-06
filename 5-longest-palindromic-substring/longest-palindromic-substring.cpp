class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";
        int start = 0, len = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                if((r - l + 1) > len)
                {
                    start = l;
                    len = r - l + 1;
                }
                l -= 1;
                r += 1;
            }

            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                if((r - l + 1) > len)
                {
                    start = l;
                    len = r - l + 1;
                }
                l -= 1;
                r += 1;
            }
        }

        return s.substr(start, len);
    }
};