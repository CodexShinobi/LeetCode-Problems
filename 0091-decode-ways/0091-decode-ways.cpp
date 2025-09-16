class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: Empty string
        dp[1] = s[0] != '0' ? 1 : 0;
        for (int i = 2; i <= n; i++) {
            int oneDigit = s[i - 1] - '0';
            int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (oneDigit >= 1 && oneDigit <= 9)
                dp[i] += dp[i - 1];
            if (twoDigits >= 10 && twoDigits <= 26)
                dp[i] += dp[i - 2];
        }
        
        return dp[n];
    }
};
// class Solution {
// public:
//     int numDecodings(string s) {
//         int n = s.size();
//         if (n == 0 || s[0] == '0') return 0;
//         int prev2 = 1, prev1 = 1; // dp[i-2] and dp[i-1]
//         for (int i = 1; i < n; i++) {
//             int curr = 0;
//             int oneDigit = s[i] - '0';
//             int twoDigits = (s[i - 1] - '0') * 10 + oneDigit;
//             if (oneDigit >= 1 && oneDigit <= 9)
//                 curr += prev1;
//             if (twoDigits >= 10 && twoDigits <= 26)
//                 curr += prev2;
//             prev2 = prev1; // Shift values
//             prev1 = curr;
//         }
//         return prev1;
//     }
// };
