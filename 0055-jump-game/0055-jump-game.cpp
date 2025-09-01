class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false; // If current index is unreachable
            maxReach = max(maxReach, i + nums[i]); // Update max reachable index
            if (maxReach >= n - 1) return true; // If last index is reachable
        }

        return true;
    }
};
