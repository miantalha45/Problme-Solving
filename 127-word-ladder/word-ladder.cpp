class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({beginWord, 1});
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            if (word == endWord)
                return level;

            for (int i = 0; i < word.length(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) continue;
                    word[i] = c;

                    if (wordSet.count(word) && !visited.count(word)) {
                        visited.insert(word);
                        q.push({word, level + 1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};