class Solution {
public:
    int getMax(vector<int>& nums, int n) {
        int ret = nums[0];
        
        for (int i = 1; i < n; ++i)
            if (nums[i] > ret)
                ret = nums[i];
            
        return ret;
    }
    
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int n = nums.size();
        
        int ans = getMax(nums, n);
        if (ans < 0)
            return ans;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) {
                currSum += nums[i];
            }
            else if (nums[i] + currSum > 0) {
                currSum += nums[i];
            }
            else {
                currSum = 0;
            }
            
            if (currSum > ans) {
                ans = currSum;
            }
        }
        
        return ans;
    }
};
