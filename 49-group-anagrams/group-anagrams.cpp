class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        vector<vector<string>> anagrams;

        for (const string& str : strs) {
            string sortedStr = sortStr(str);
            dict[sortedStr].push_back(str);
        }

        for (auto& pair : dict) {
            anagrams.push_back(pair.second);
        }

        return anagrams;
    }

private:
    string sortStr(const string& str) {
        string sorted = str;
        sort(sorted.begin(), sorted.end());
        return sorted;
    }
};