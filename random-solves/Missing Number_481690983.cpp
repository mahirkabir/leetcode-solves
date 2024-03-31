class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        long long sum = (n * (n + 1)) / 2;
        long long tot = 0;
        
        for (int i = 0; i < n; ++i)
            tot += nums[i];
        
        return sum - tot;
    }
};
