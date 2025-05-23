class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;

        int i = 0;
        while(i < s.size())
        {
            if(!stk.empty() && s[i] == '*')
            {
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
            i++;
        }

        string str = "";
        while(!stk.empty())
        {
            str += stk.top();
            stk.pop();
        }

        reverse(str.begin(), str.end());

        return str;
    }
};