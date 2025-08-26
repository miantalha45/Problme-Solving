class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;

        map<int, int> freq;

        for (int num : hand) {
            freq[num]++;
        }

        while (!freq.empty()) {
            int minCard =
                freq.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                if (freq.find(minCard + i) == freq.end()) {
                    return false;
                }
                freq[minCard + i]--;
                if (freq[minCard + i] == 0) {
                    freq.erase(minCard + i);
                }
            }
        }

        return true;
    }
};