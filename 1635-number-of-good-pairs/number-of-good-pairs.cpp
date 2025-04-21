class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int, int> map;
        int res = 0;
        for(int i=0; i < nums.size(); i++)
        {
            if(map.count(nums[i]) > 0)
            {
                map[nums[i]]++;
            }
            else{
                map[nums[i]] = 1;
            }
        }

        for(auto& pair : map)
        {
            int count = pair.second * (pair.second - 1) / 2;
            res += count;
        }
        return res;
    }
};