class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;

int i = 0;
while(i < s.size())
{
	if(!stk.empty() && stk.top() == s[i])
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