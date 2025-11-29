// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int zeros, ones, twos;
//         zeros = ones = twos = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == 0) {
//                 zeros++;
//             } else if (nums[i] == 1) {
//                 ones++;
//             } else {
//                 twos++;
//             }
//         }
//         int i=0;
//         while(zeros--){
//             nums[i]=0;
//         }
//         while(ones--){
//             nums[i]=1;
//         }
//         while(twos--){
//             nums[i]=2;
//         }
    
//     };
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0)
                swap(nums[low++], nums[mid++]);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[high--]);
        }
    }
};
