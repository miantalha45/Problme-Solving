class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;

        for(int j = 0; j < nums.size(); j++)
        {
            int complement = target - nums[j];
            if(map.count(complement) > 0)
            {
                int temp = map[target - nums[j]];
                res.push_back(j);
                res.push_back(temp);
                return res;
            }
            map[nums[j]] = j;
        }

        return res;
    }
};