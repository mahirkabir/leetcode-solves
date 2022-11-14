class Solution {
public:
    long long getRev(int num) {
        long long ret = 0;
        
        while(num > 0) {
            ret *= 10;
            ret += (num % 10);
            num /= 10;
        }
        
        return ret;
    }
    
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int revX = getRev(x);
        return x == revX;
    }
};
