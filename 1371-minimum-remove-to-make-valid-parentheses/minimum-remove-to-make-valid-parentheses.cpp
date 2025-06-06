class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<char> res;
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                res.push_back(c);
                count += 1;
            }
            else if (c == ')' && count > 0) {
                res.push_back(c);
                count -= 1;
            }
            else if (c != ')') {
                res.push_back(c);
            }
        }

        string str = "";
        for (int i = res.size() - 1; i >= 0; i--) {
            if (res[i] == '(' && count > 0) {
                count -= 1;
            } else {
                str += res[i];  
            }
        }

        reverse(str.begin(), str.end());
        return str;
    }
};