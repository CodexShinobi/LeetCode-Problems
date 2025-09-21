class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        int left = 0;

        for(int x : nums) total += x;   // total sum of array

        for(int i = 0; i < nums.size(); i++){
            if(left == total - left - nums[i]) // check pivot condition
                return i;
            left += nums[i];
        }

        return -1;  // no pivot found
    }
};
