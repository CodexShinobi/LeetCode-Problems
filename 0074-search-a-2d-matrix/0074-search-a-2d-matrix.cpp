
// class Solution {
// public:
//     // Binary search within a specific row of a 2D matrix
//     bool searchInRow(vector<vector<int>>& mat, int target) {
    //     int n = mat[0].size();
    //     int st = 0, end = n - 1;

    //     while (st <= end) {
    //         int mid = st + (end - st) / 2;

    //         if (target == mat[row][mid]) {
    //             return true;
    //         } else if (target > mat[row][mid]) {
    //             st = mid + 1;
    //         } else {
    //             end = mid - 1;
    //         }
    //     }

    //     return false; // Element not found in row
    // }

    // // Search the entire matrix row by row
    // bool searchMatrix(vector<vector<int>>& mat, int target) {
    //     int m = mat.size();

    //     for (int row = 0; row < m; row++) {
    //         // Only search the row if target could exist in it
    //         if (target >= mat[row][0] && target <= mat[row].back()) {
    //             if (searchInRow(mat, target, row)) {
    //                 return true;
    //             }
    //         }
    //     }

    //     return false; // Element not found in any row
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();         // number of rows
        int m = matrix[0].size();      // number of columns
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};


