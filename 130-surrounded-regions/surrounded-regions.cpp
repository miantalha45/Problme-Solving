class Solution {
public:
    void capture(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || col < 0 || row == board.size() ||
            col == board[0].size() || board[row][col] != 'O')
            return;

        board[row][col] = '#';
        capture(board, row + 1, col);
        capture(board, row - 1, col);
        capture(board, row, col + 1);
        capture(board, row, col - 1);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // 1. DFS -> Capture unsurrounded Regions (O -> #)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && (i == 0 || i == n - 1) ||
                    (j == 0 || j == m - 1))
                    capture(board, i, j);
            }
        }

        // 2. Capture Surrounded Regions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        // 3. Uncapture Surrounded Region
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};