class Solution {
public:
    map <long long, double> mp;
    double myPow(double x, int n) {
        int sign = (n < 0)?-1:1;
        n = (n < 0)?-n:n;
        
        if(n == 0) return 1;
        if(n == 1) {
            if(sign == 1) return x;
            return 1 / x;
        }
        if(mp[n]) return mp[n];
        
        long long tmp = 1;
        double num = x;
        while(tmp*2 <= n) {
            num *= num;
            tmp *= 2;
            mp[tmp] = num;
        }
        double ret = num * myPow(x, n - tmp);
        if(sign == -1) ret = 1 / ret;
        return ret;
    }
};
