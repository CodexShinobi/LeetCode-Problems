class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            
            // If array is already sorted
            if (nums[lo] <= nums[hi]) 
                return nums[lo];
            
            // Check if mid is pivot (minimum element)
            if (mid > 0 && nums[mid - 1] > nums[mid]) 
                return nums[mid];
            
            // Decide which half to search
            if (nums[lo] <= nums[mid]) 
                lo = mid + 1;
            else 
                hi = mid - 1;
        }
        return -1; // should never reach here
    }
};
