class Solution {
public:
    // int reverse(int x) {
        
    int reverse(int x) {
        long long rev = 0;            // use long long to detect overflow safely
        long long n = x;              // work with signed value

        while (n != 0) {
            int digit = n % 10;       // extract last digit
            rev = rev * 10 + digit;   // append digit

            // Early overflow check: if rev is outside 32-bit signed int range, return 0
            if (rev < numeric_limits<int>::min() || rev > numeric_limits<int>::max())
                return 0;

            n /= 10;                  // drop last digit
        }

        return static_cast<int>(rev);
    }
};