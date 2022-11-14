class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        
        int firstNonNeg = -1;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, nums[i]);
            if (nums[i] >= 0 && firstNonNeg == -1)
                firstNonNeg = i;
        }
            
        if (firstNonNeg == -1)
            return ans;
        
        int curr = nums[firstNonNeg];
        for (int i = firstNonNeg + 1; i < n; ++i) {
            if (curr + nums[i] < 0) {
                curr = 0;
            }
            else {
                curr += nums[i];
            }
            
            ans = max(ans, curr);
            // cout << nums[i] << " ... " << ans << " ~ " << curr << endl;
        }
        
        return ans;
    }
};
