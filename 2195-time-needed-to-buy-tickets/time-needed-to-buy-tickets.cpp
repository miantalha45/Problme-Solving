class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) { 
        queue<pair<int, int>> q;

        for(int i = 0; i < tickets.size(); i++)
        {
            q.push({tickets[i], i});
        }
        int timeTaken = 0;
        while(!q.empty())
        {
            auto [value, index] = q.front();
            q.pop();
            if(index == k && value == 1)
            {
                return timeTaken += 1;
            }
            if(value > 0)
            {
                q.push({value - 1, index});
                timeTaken++;
            }
        }

        return timeTaken;
    }
};