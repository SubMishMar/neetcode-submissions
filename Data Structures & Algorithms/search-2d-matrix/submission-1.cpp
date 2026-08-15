class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n_rows = matrix.size();
        int n_cols = matrix[0].size();
        int l = 0;
        int r = n_rows*n_cols - 1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int row_mid = mid / n_cols;
            int col_mid = mid % n_cols;
            if (matrix[row_mid][col_mid] < target) {
                l = mid + 1;
            } else if (matrix[row_mid][col_mid] > target) {
                r = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
