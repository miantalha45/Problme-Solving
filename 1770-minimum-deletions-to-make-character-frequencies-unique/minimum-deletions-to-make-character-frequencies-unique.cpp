class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);

        for(char c : s)
        {
            freq[c - 'a']++;
        }

        unordered_set<int> usedFreq;
        int deletions = 0;

        for(int f : freq)
        {
            int currentFreq = f;
            while(currentFreq > 0 && (usedFreq.count(currentFreq) > 0))
            {
                currentFreq--;
                deletions++;
            }
            usedFreq.insert(currentFreq);
        }

        return deletions;
    }
};