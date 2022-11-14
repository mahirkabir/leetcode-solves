class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        k = k%n;
        
        vector<int> ans = nums;
        
        int st = 0;
        int en = n - 1;
        
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = nums[en--];
        }
        
        for (int i = k; i < n; ++i) {
            ans[i] = nums[st++];
        }
        
        nums = ans;
    }
};
