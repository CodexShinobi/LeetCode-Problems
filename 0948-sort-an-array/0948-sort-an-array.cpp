// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         // easiest way to sort by using begin,end
//         sort(nums.begin(),nums.end());
//         return nums;
//     }
// };
        //  can dp with recursion
// class Solution {
// public:
//     void insert(vector<int>& v, int temp) {
//         // base condition
//         if (v.size() == 0 || v.back() <= temp) {
//             v.push_back(temp);
//             return;
//         }

//         int val = v.back();
//         v.pop_back();
//         insert(v, temp);
//         v.push_back(val);
//     }

//     void sortRec(vector<int>& v) {
//         if (v.size() <= 1) return; // base case

//         int temp = v.back();
//         v.pop_back();

//         sortRec(v);
//         insert(v, temp);
//     }

//     vector<int> sortArray(vector<int>& nums) {
//         sortRec(nums);
//         return nums;
    

//     }
// };
class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> temp;
        int i = l, j = m + 1;

        while (i <= m && j <= r) {
            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while (i <= m) temp.push_back(nums[i++]);
        while (j <= r) temp.push_back(nums[j++]);

        for (int k = l; k <= r; k++) {
            nums[k] = temp[k - l];
        }
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

