class Solution {
public:
    int findComplement(int num) {
        int ret = 0;
        int pow = 1;
        
        while(num > 0) {
            ret += (1 - num % 2) * pow;
            
            num /= 2;
            
            pow *= 2;
        }
        
        return ret;
    }
};
