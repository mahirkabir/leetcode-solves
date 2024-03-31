// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long lo = 1;
        long long hi = n;
        while(lo <= hi) {
            long long mid = lo + ( hi - lo ) / 2;
            if(guess(mid) == 0) return mid;
            if(guess(mid) == -1) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
