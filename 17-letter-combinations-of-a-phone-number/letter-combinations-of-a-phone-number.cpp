class Solution {
public:
    unordered_map<char, string> digitMap = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return vector<string>();
        }
        vector<string> result;
        backtrack(digits, 0, "", result);
        return result;
    }

private:
    void backtrack(string digits, int index, string current, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        char digit = digits[index];
        string letters = digitMap[digit];

        for (char letter : letters) {
            backtrack(digits, index + 1, current + letter, result);
        }
    }
};