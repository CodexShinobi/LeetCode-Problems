class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // stores indexes of useful elements
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Remove out of window index
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // Remove smaller elements from back
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Start adding to result when window reaches size k
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
