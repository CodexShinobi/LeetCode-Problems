class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            count += n & 1;  // agr increment count less than 1 h to...
            n >>= 1;         // check the right bit and shift by 1
        }
        return count;
    }
};
