class Solution {
public:
    int N;
    int dp[1000 + 5];
    vector<int> arr;
    
    int DP(int pos) {
        if(pos >= N)
            return 0;
        
        int &ret = dp[pos];
        if(ret != -1)
            return ret;
        
        int p1 = arr[pos] + DP(pos + 2);
        int p2 = DP(pos + 1);
        
        return ret = (p1 > p2) ? p1 : p2;
    }
    
    int rob(vector<int>& nums) {
        N = nums.size();
        
        memset(dp, -1, sizeof dp);
        
        arr = nums;
        
        return DP(0);
    }
};
