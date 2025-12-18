class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0, maxlen = 1;

        for (int i = 0; i < n; i++) {
            // odd length palindromes centered at i
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxlen) {
                    start = l;                  // must be l, not 1
                    maxlen = r - l + 1;
                }
                l--;
                r++;
            }

            // even length palindromes centered between i and i+1
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {   // must be ==, not =
                if (r - l + 1 > maxlen) {
                    start = l;              // must be l, not 1
                    maxlen = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, maxlen);
    }
};
