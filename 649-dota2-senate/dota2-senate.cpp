class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> d;
        queue<int> r;
        int n = senate.size();
        for(int i = 0; i < n; i++)
        {
            if(senate[i] == 'R')
            {
                r.push(i);
            }
            else{
                d.push(i);
            }
        }

        while(!d.empty() && !r.empty())
        {
            if(d.front() < r.front())
            {
                r.pop();
                d.push(d.front() + n);
                d.pop();
            }
            else{
                d.pop();
                r.push(r.front() + n);
                r.pop();
            }
        }

        return d.empty() ? "Radiant" : "Dire";
    }
};