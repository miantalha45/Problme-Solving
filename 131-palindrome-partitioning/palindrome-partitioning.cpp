class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(s, 0, path);
        return res;
    }

private:
    void backtrack(string &s, int start, vector<string> &path) {
        if(start == s.size())
        {
            res.push_back(path);
            return;
        }

        for(int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, path);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};