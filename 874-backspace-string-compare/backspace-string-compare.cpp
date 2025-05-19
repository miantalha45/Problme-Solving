class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_stack;
        stack<char> t_stack;
        int i = 0;
        int j = 0;
        while(i < s.size())
        {
            if(s[i] == '#' && !s_stack.empty())
            {
                s_stack.pop();
            }
            else if(s[i] != '#'){
                s_stack.push(s[i]);
            }
            i++;
        }
        
        while(j < t.size())
        {

            if(t[j] == '#' && !t_stack.empty())
            {
                t_stack.pop();
            }
            else if(t[j] != '#'){
                t_stack.push(t[j]);
            }
            j++;
        }

        while(!s_stack.empty() && !t_stack.empty())
        {
            if(s_stack.top() == t_stack.top()) 
            {
                s_stack.pop();
                t_stack.pop();
            }
            else{
                return false;
            }
        }
        return s_stack.size() == t_stack.size() ? true : false;
    }
};