class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk.push(s[i]);
            }
            else 
            {
                if(stk.size() == 0)
                {
                    return false;
                }
            if(s[i] == ')'){
                if(stk.top() != '(')
                {
                    return false;
                }
                else{
                    stk.pop();
                }
            }
            else if(s[i] == '}'){
                if(stk.top() != '{')
                {
                    return false;
                }
                else{
                    stk.pop();
                }
            }
            else if(s[i] == ']'){
                if(stk.top() != '[')
                {
                    return false;
                }
                else{
                    stk.pop();
                }
                }
            }
            i++;
        }

        if(stk.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};