class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        long long sum = 0, mx = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {
            sum += nums[j];
            freq[nums[j]]++;

            // shrink window if size > k
            if (j - i + 1 > k) {
                freq[nums[i]]--;
                sum -= nums[i];
                if (freq[nums[i]] == 0) freq.erase(nums[i]);
                i++;
            }

            // if window size == k and all elements are distinct
            if (j - i + 1 == k && freq.size() == k) {
                mx = max(mx, sum);
            }
        }
        return mx;
    }
};
