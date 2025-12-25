// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//       vector<int> v;
//         stack<int> s;
//         int size = nums2.size();

//         for (int i = size - 1; i >= 0; i--) {
//             if (s.size() == 0) {
//                 v.push_back(-1);
//             }
//             else if (s.size() > 0 && s.top() > nums2[i]) {
//                 v.push_back(s.top());
//             }
//             else if (s.size() > 0 && s.top() <= nums2[i]) {
//                 while (s.size() > 0 && s.top() <= nums2[i]) {
//                     s.pop();
//                 }
//                 if (s.size() == 0) {
//                     v.push_back(-1);
//                 }
//                 else {
//                     v.push_back(s.top());
//                 }
//             }
//             s.push(nums2[i]);
//         }

//         reverse(v.begin(), v.end()); // because we pushed from right to left

//         // Map the results for nums1
//         unordered_map<int, int> mp;
//         for (int i = 0; i < size; i++) {
//             mp[nums2[i]] = v[i];
//         }

//         vector<int> ans;
//         for (int num : nums1) {
//             ans.push_back(mp[num]);
//         }

//         return ans;   
//     }
// };
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nge; // value -> next greater value

        // Step 1: compute NGE for every num in nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int x = nums2[i];

            while (!st.empty() && st.top() <= x)
                st.pop();

            nge[x] = st.empty() ? -1 : st.top();
            st.push(x);
        }

        // Step 2: build result for nums1 using the map
        vector<int> ans;
        ans.reserve(nums1.size());

        for (int x : nums1) {
            ans.push_back(nge[x]);   // nums1 is subset of nums2, so x is in map
        }

        return ans;
    }
};
