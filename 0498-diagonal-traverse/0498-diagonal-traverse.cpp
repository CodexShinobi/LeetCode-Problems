class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);

        int row = 0, col = 0;
        bool up = true; // direction flag

        while (result.size() < m * n) {
            result.push_back(mat[row][col]);

            if (up) {
                if (col == n - 1) {       // right boundary
                    row++;
                    up = false;
                } else if (row == 0) {    // top boundary
                    col++;
                    up = false;
                } else {                  // move diagonally up-right
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) {       // bottom boundary
                    col++;
                    up = true;
                } else if (col == 0) {    // left boundary
                    row++;
                    up = true;
                } else {                  // move diagonally down-left
                    row++;
                    col--;
                }
            }
        }
        return result;
    }
};
