class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        long long sum = 1;
        
        for(int i = 2; i*i <= num; ++i) {
            if(num % i == 0) {
                if(i == num / i) sum += i;
                else sum += i + (num / i);
            }
        }
        
        return num == sum;
    }
};
