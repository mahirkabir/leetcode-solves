class Solution {
public:
    
    int dp[50];
    int climbStairsDP(int n) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        
        int &ret = dp[n];
        if (ret != -1)
            return ret;
        
        int p1 = climbStairsDP(n - 1);
        int p2 = climbStairsDP(n - 2);
        
        return ret = p1 + p2;
    }
    
    int climbStairs(int n) {
        memset(dp, -1, sizeof dp);
        return climbStairsDP(n);
    }
};
