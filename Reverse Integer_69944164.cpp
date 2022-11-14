class Solution {
public:
    int reverse(int x) {
        if(x == 0) return x;
        int sign = x/(abs(x));
        x = abs(x);
        long long ret = 0;
        while(x > 0) {
            ret = ret*10 + (x%10);
            x /= 10;
        }
        if(ret > INT_MAX) ret = 0;
        ret *= sign;
        return ret;
    }
};
