class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int leftMax = 0, rightMax = 0, water = 0;

        while (l < r) {
            if (h[l] < h[r]) {
                leftMax = max(leftMax, h[l]);
                water += leftMax - h[l];
                l++;
            } else {
                rightMax = max(rightMax, h[r]);
                water += rightMax - h[r];
                r--;
            }
        }
        return water;
    }
};
