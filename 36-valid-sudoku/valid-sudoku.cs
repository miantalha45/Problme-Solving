public class Solution {
    public bool IsValidSudoku(char[][] board) {
        HashSet<string> seen = new HashSet<string>();

        for(int i = 0;i < 9;i++)
        {
            for(int j = 0;j < 9;j++)
            {
                char ch = board[i][j];
                if(ch != '.')
                {
                    string rowKey = $"row{i}-{ch}";
                    string colKey = $"col{j}-{ch}";
                    string squareKey = $"box{i / 3}{j / 3}-{ch}";

                    if(!seen.Add(rowKey) || !seen.Add(colKey) || !seen.Add(squareKey))
                        return false;
                }
            }         
        }

        return true;
    }
}