class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int trustSize = trust.size();

        if(trustSize == 0 && n == 1) return n;
        unordered_map<int, vector<int>> list;
        unordered_map<int, int> trustedMap;

        for (int i = 0; i < trustSize; i++) {
            int trusting = trust[i][0];
            int trusted = trust[i][1];

            list[trusting].push_back(trusted);

            if (trustedMap.count(trusted) > 0) {
                trustedMap[trusted]++;
            } else {
                trustedMap[trusted] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (list.count(i) == 0 && trustedMap.count(i) > 0 &&
                trustedMap[i] == n-1) {
                return i;
            }
        }

        return -1;
    }
};