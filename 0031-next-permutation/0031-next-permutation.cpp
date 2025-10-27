class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int ind = -1;
        int n = A.size();

        
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: If no such index found, reverse the entire array
        if (ind == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Step 3: Find the smallest number larger than A[ind] from the right side
        for (int i = n - 1; i > ind; i--) {
            if (A[i] > A[ind]) {
                swap(A[i], A[ind]);
                break;
            }
        }

        // Step 4: Reverse the right half
        reverse(A.begin() + ind + 1, A.end());
    }
};
