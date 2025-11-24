class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;

        // Count frequency
        for(char c : s) freq[c]++;

        int n = s.length();
        char maxChar = 0;
        int maxFreq = 0;

        // Find max frequency char
        for (auto &p : freq) {
            if (p.second > maxFreq) {
                maxFreq = p.second;
                maxChar = p.first;
            }
        }

        // If impossible to rearrange
        if (maxFreq > (n + 1) / 2) 
            return "";

        vector<char> res(n);
        int idx = 0;

        // Place the highest frequency character first
        while (freq[maxChar] > 0) {
            res[idx] = maxChar;
            idx += 2;
            freq[maxChar]--;
        }

        // Place remaining characters
        for (auto &p : freq) {
            char ch = p.first;
            int count = p.second;

            while (count > 0) {
                if (idx >= n) idx = 1;  // switch to odd positions

                res[idx] = ch;
                idx += 2;
                count--;
            }
        }

        return string(res.begin(), res.end());
    }
};
