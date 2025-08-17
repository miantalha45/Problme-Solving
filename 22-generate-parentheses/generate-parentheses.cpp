class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        AddParenthesis(result, n, "", 0, 0);
        return result;
    }

    void AddParenthesis(vector<string>& result, int n, string brace,
                        int openCount, int closeCount) {
        if (openCount == n && closeCount == n) {
            result.push_back(brace);
        }
        if (openCount < n) {
            AddParenthesis(result, n, brace + "(", openCount + 1, closeCount);
        }
        if (closeCount < openCount && closeCount < n)
        {
            AddParenthesis(result, n, brace + ")", openCount, closeCount + 1);
        }
    }
};