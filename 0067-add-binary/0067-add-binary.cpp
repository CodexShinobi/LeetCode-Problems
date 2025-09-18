#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int total = carry;
            if (i >= 0) total += a[i--] - '0';  // convert char to int
            if (j >= 0) total += b[j--] - '0';

            result += (total % 2) + '0';  // append current bit
            carry = total / 2;            // update carry
        }

        reverse(result.begin(), result.end());  // reverse final result
        return result;
    }
};
