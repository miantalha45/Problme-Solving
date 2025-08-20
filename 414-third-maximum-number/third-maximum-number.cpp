class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> set;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(const auto& num : nums)
        {
            if(set.count(num) == 0)
            {
                set.insert(num);
                minHeap.push(num);

                if(minHeap.size() > 3)
                {
                    minHeap.pop();
                }
            }
        }

        if (minHeap.size() < 3) {
            int maxVal = minHeap.top();
            while (!minHeap.empty()) {
                maxVal = max(maxVal, minHeap.top());
                minHeap.pop();
            }
            return maxVal;
        }
        
        return minHeap.top();
    }
};