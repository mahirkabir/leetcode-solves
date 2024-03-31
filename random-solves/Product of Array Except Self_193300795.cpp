class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zidx = -1;
        int n = nums.size();
        long long mult = 1;
        vector<int> ans(n);
        
        for(int i = 0; i < n; ++i) {
            zidx = (nums[i] == 0)?(zidx == -1)?i:-2:zidx;
            mult = (nums[i] == 0)?mult:mult * nums[i];
        }
        
        if(zidx >= 0) {
            ans[zidx] = mult;
        }
        else if(zidx == -1) {
            for(int i = 0; i < n; ++i) {
                ans[i] = mult / nums[i];   
            }
        }
        
        return ans;
    }
};
