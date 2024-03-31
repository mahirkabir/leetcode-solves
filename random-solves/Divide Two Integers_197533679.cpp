class Solution {
public:
    int divide(long n, long d) {
        int sign = ((n < 0 && d > 0) || (n > 0 && d < 0)) ? -1:1;
        
        //cout << n << " " << d << endl;
        //cout << n << " " << (n < 0) << " " << (-n) <<  endl;
        n = (n < 0) ? -n:n;
        d = (d < 0) ? -d:d;
        
        //cout << n << " " << d << endl;
        
        long res = sign * call(n, d);
        
        //cout << call(n, d) << " " << res << " " << sign << endl;
        
        if(res < INT_MIN)
            return INT_MIN;
        if(res > INT_MAX)
            return INT_MAX;
        return res;
    }
    
    long call(long n, long d) {
        //cout << n << " " << d << endl;
        if(d == 1)
            return n;
        
        long ans = 0;
        
        while(n >= d) {
            long curr = d;
            long mult = 1;
            
            while(curr + curr <= n) {
                curr += curr; //3+3=6, 6+6=12
                mult += mult; //1+1=2, 2+2=4
            }
            
            ans += mult;
            n -= curr;
            //cout << "ans: " << ans << endl;
        }
        
        return ans;
    }
};

/*
    n=10 d=3

    3->6
    1->2
    2

    3
    1
    2+1=3

    1<3 => return 3
*/
