class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> diagonalUsed(2 * n - 1, false);
        vector<bool> antiDiagonalUsed(2 * n - 1, false);
        vector<bool> columnUsed(n, false);
        vector<vector<string>> result;
        vector<string> current;
        backtrack(0, n, current, result, diagonalUsed, antiDiagonalUsed,
                  columnUsed);
        return result;
    }

private:
    void backtrack(int row, int n, vector<string>& current,
                   vector<vector<string>>& result, vector<bool>& diagonalUsed,
                   vector<bool>& antiDiagonalUsed, vector<bool>& columnUsed) {
        if (current.size() == n) {
            result.push_back(current);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(n, row, col, diagonalUsed, antiDiagonalUsed,
                       columnUsed)) {
                // Create a row string with a queen at position col
                string rowStr(n, '.');
                rowStr[col] = 'Q';
                current.push_back(rowStr);
                
                // Mark as used
                diagonalUsed[row - col + (n - 1)] = true;
                antiDiagonalUsed[row + col] = true;
                columnUsed[col] = true;
                
                backtrack(row + 1, n, current, result, diagonalUsed,
                          antiDiagonalUsed, columnUsed);
                
                // Backtrack: unmark and remove
                current.pop_back();
                diagonalUsed[row - col + (n - 1)] = false;
                antiDiagonalUsed[row + col] = false;
                columnUsed[col] = false;
            }
        }
    }

    bool isSafe(int n, int row, int col, vector<bool>& diagonalUsed,
                vector<bool>& antiDiagonalUsed, vector<bool>& columnUsed) {
        return diagonalUsed[row - col + (n - 1)] == false &&
               antiDiagonalUsed[row + col] == false && 
               columnUsed[col] == false;
    }
};