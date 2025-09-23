class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(),
                                    vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, visited, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& visited,
             string word, int index, int row, int col) {
        // Check bounds first
        if (row < 0 || row >= board.size() || col < 0 ||
            col >= board[0].size()) {
            return false;
        }

        // Check if already visited or character doesn't match
        if (visited[row][col] || board[row][col] != word[index]) {
            return false;
        }

        // Check if we've matched the entire word
        if (index == word.size() - 1) { // Last character matched!
            return true;
        }

        visited[row][col] = 1;

        // Explore 4 directions with index + 1
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int d = 0; d < 4; d++) {
            int newRow = row + directions[d][0];
            int newCol = col + directions[d][1];

            if (dfs(board, visited, word, index + 1, newRow, newCol)) {
                return true;
            }
        }

        visited[row][col] = 0;
        return false;
    }
};