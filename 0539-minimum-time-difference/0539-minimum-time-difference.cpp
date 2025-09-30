class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        // Convert HH:MM -> total minutes
        for (string &t : timePoints) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }

        sort(minutes.begin(), minutes.end());
        int sz = minutes.size();
        int ans = INT_MAX;

        // Check adjacent differences
        for (int i = 1; i < sz; i++) {
            ans = min(ans, minutes[i] - minutes[i - 1]);
        }

        // Wrap-around case (last - first across midnight)
        ans = min(ans, 1440 - (minutes[sz - 1] - minutes[0]));

        return ans;
    }
};
