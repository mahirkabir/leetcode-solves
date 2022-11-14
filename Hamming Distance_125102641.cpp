class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        
        while(true) {
            if(x == 0 && y == 0) break;
            
            int bitX = 0, bitY = 0;
            
            if(x > 0) {
                bitX = x % 2;
                x /= 2;
            }
            
            if(y > 0) {
                bitY = y % 2;
                y /= 2;
            }
            
            cnt += (bitX != bitY);
        }
        
        return cnt;
    }
};
