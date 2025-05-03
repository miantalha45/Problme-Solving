class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> map;
        stack<int> stk;

        for (int num : nums2) {
            while (!stk.empty() && stk.top() < num) {
                int topVal = stk.top();
                stk.pop();
                map[topVal] = num;  
            }
            stk.push(num);
        }

        for (int i = 0; i < nums1.size(); i++) {
            res[i] = map.count(nums1[i]) > 0 ? map[nums1[i]] : -1;
        }

        return res;
    }
};