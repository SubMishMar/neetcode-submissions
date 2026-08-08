class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n_cols = matrix[0].size();
        int n_rows = matrix.size();
        int left = 0;
        int right = n_cols*n_rows-1;
        while(left <= right) {
            int mid = (left+right)/2;
            int mid_row = mid/n_cols;
            int mid_col = mid%n_cols;
            if(matrix[mid_row][mid_col] < target) {
                left = mid+1;
            } else if (target < matrix[mid_row][mid_col]) {
                right = mid-1;
            } else {
                return true;
            }
        } 
        return false;
    }
};
