class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<string> set;
        int res = 0;
        for(int i = 0; i < jewels.length(); i++)
        {
            string ch(1, jewels[i]);
            if (set.count(ch) == 0) {
                set.insert(ch);
            }
        }

        for(int j = 0; j < stones.length(); j++)
        {
            string ch(1, stones[j]);
            if(set.count(ch) == 1)
            {
                res += 1;
            }
        }

        return res;
        
    }
};