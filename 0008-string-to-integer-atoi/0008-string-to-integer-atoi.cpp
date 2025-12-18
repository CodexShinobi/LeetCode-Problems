class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // 1) Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2) Handle optional sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3) Read digits and build number with overflow check
        long long num = 0;   // use long long for safe overflow detection
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            num = num * 10 + digit;

            // If beyond 32-bit range, clamp early
            if (sign == 1 && num > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -num < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return (int)(sign * num);
    }
};
