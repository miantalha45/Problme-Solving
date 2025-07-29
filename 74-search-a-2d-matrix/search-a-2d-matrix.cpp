class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = (matrix[0]).size();
        int rows = matrix.size();

        int left = 0, right = cols * rows - 1;
        while(left <= right)
        {
            int midIndex = left + (right - left) / 2;

            int row = midIndex / cols;
            int col = midIndex % cols;

            int n = matrix[row][col];
            if(target == n)
                return true;
            else if(target > n)
                left = midIndex + 1;
            else
                right = midIndex - 1;
        }

        return false;
    }
};