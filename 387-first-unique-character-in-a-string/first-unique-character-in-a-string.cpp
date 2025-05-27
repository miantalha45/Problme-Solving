class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, vector<int>> map;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (map.find(ch) == map.end()) {
                map[ch] = {i};
            } else {
                map[ch].push_back(i);
            }
        }

        for(char ch : s)
        {
            if(map[ch].size() == 1)
            {
                return map[ch][0];
            }
        }

        return -1;

    }
};