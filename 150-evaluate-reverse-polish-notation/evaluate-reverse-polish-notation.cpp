class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (const string& s : tokens) {
            if (s == "+") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a + b);
            } else if (s == "-") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a - b);
            } else if (s == "*") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a * b);
            } else if (s == "/") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a / b);
            } else {
                stk.push(stoi(s));
            }
        }

        return stk.top();
    }
};