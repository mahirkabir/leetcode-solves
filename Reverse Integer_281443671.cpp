class Solution {
public:
    int reverse(long long x) {
        if(x == 0)
            return x;
        
        int sign = x / abs(x);
        x = x / sign;
        
        long long tot = 0;
        
        while(x > 0) {
            tot = tot * 10 + (x % 10);
            x /= 10;
        }
        
        if(tot < INT_MIN || tot > INT_MAX)
            tot = 0;
        
        return tot * sign;
    }
};
