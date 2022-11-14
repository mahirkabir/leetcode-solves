class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret = nums;
        
        int pos = n - 1;
        int st = 0, en = n - 1;
        
        while(st <= en) {
            if (st != en) {
                if (nums[st] * nums[st] > nums[en] * nums[en]) {
                    ret[pos--] = nums[st] * nums[st];
                    st++;
                }
                else {
                    ret[pos--] = nums[en] * nums[en];
                    en--;
                }
            }
            else {
                ret[pos--] = nums[st] * nums[st];
                break;
            }
        }
        
        return ret;
    }
};
