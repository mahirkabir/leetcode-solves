class Solution {
public:
    vector<int> v;
    int n;
    int dp[1000 + 5][2];
    
    int DP(int pos, int preTaken) {
        if(pos == n)
            return 0;
        
        int &ret = dp[pos][preTaken];
        if(ret != -1)
            return ret;
        
        int p1 = 0, p2 = 0;
        if(preTaken == 0)
            p1 = v[pos] + DP(pos + 1, 1);
        
        p2 = DP(pos + 1, 0);
        
        return ret = max(p1, p2);
    }
    
    int rob(vector<int>& nums) {
        v = nums;
        n = v.size();
        memset(dp, -1, sizeof dp);
        return DP(0, 0);
    }
};
