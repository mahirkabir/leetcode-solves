class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n % 2 == 0 && n) n /= 2;
        return n == 1;
    }
};
