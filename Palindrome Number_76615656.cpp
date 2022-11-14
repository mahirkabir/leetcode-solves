class Solution {
public:
    bool isPalindrome(int x) {
        int altx = 0;
        int tmpx = x;
        while(tmpx) altx = altx*10 + (tmpx%10), tmpx /= 10;
        return x == altx && x >= 0;
    }
};
