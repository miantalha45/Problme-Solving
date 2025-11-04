class Solution {
public:
    int total = 0;
    void isLands(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || col < 0 || row == board.size() ||
            col == board[0].size() || board[row][col] != '1')
            return;

        board[row][col] = '0';

        isLands(board, row + 1, col);
        isLands(board, row - 1, col);
        isLands(board, row, col + 1);
        isLands(board, row, col - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    isLands(grid, i, j);
                    total++;
                }
            }
        }

        return total;
    }
};