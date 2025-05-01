class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, char> map_s_to_t;
        unordered_map<char, char> map_t_to_s;

        for(int i = 0; i < s.size(); i++)
        {
            if(map_s_to_t.count(s[i]) > 0)
            {
                if(map_s_to_t[s[i]] != t[i]) return false;
            }
            else{
                map_s_to_t[s[i]] = t[i];
            }

            if(map_t_to_s.count(t[i]) > 0)
            {
                if(map_t_to_s[t[i]] != s[i]) return false;
            }
            else{
                map_t_to_s[t[i]] = s[i];
            }
        }

        return true;
    }
};