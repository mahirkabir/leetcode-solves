class Solution {
public:
    bool isPowerOfFour(int num) {
        return __builtin_popcount(num) == 1 && __builtin_ctz(num) % 2 == 0;
    }
};
