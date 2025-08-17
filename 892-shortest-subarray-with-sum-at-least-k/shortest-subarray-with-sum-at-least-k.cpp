class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;

        vector<long> prefixSum(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        int res = INT_MAX;

        for (int j = 0; j <= n; j++) {
            while (!q.empty() && prefixSum[j] - prefixSum[q.front()] >= k) {
                res = min(res, j - q.front());
                q.pop_front();
            }

            while (!q.empty() && prefixSum[q.back()] >= prefixSum[j]) {
                q.pop_back();
            }

            q.push_back(j);
        }

        return res == INT_MAX ? -1 : res;
    }
};