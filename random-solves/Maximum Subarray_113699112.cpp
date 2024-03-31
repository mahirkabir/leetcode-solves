class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = 0;
        int mx = -(1 << 31);
        int n = nums.size();
        int curr = 0;
        
        for(int i = 0; i < n; ++i) {
            if(nums[i] < 0 && curr <= -nums[i]) {
                ret = max(ret, curr);
                curr = 0;
            }
            else {
                curr += nums[i];
                ret = max(ret, curr);
            }
            mx = max(mx, nums[i]);
        }
        
        ret = max(ret, curr);
        
        if(mx < 0) return mx;
        return ret;
    }
};
