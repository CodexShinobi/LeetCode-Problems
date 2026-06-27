class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if the required number already exists
            if (indexMap.find(complement) != indexMap.end()) {
                return {indexMap[complement], i};
            }

            // Store the current number and its index
            indexMap[nums[i]] = i;
        }

        return {};
    }
};