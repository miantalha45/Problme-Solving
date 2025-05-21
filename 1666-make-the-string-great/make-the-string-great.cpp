class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for (char ch : s) {
            if (!stk.empty() && abs(ch - stk.top()) == 32) {
                stk.pop();
            } else {
                stk.push(ch);
            }
        }

        string str = "";
        while (!stk.empty()) {
            str += stk.top();
            stk.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};