class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int start = arr[i][0];
            int end = arr[i][1];

            if (!ans.empty() && start <= ans.back()[1]) {
                // merge intervals
                ans.back()[1] = max(ans.back()[1], end);
            } else {
                ans.push_back({start, end});
            }
        }
        return ans;
    }
};
