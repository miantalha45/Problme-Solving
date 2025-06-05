class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int curSum = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for(int n : nums)
        {
            curSum += n;
            int diff = curSum - k;
            if(map.count(diff) > 0)
            {
                res += map[diff];
            }
            if(map.count(curSum) > 0)
            {
                map[curSum]++;
            }
            else{
                map[curSum] = 1;
            }
        }

        return res;
    }
};