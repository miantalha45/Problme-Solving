class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        if(n == 1)
            return {0};
        
        stack<int> s;
        vector<int> result(n, 0);

        for(int i = 0;i < n;i++)
        {
            while(!s.empty() && temperatures[s.top()] < temperatures[i])
            {
                result[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        return result;
    }
};