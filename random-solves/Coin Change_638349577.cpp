class Solution {
public:
    int dp[10 + 5][10000 + 5];
    
    int DP(vector<int>& coins, int n, int pos, int tot) {
        if (pos == n)
            if (tot == 0)
                return 0;
            else
                return INT_MAX;
        
        if (tot == 0)
            return 0;
        
        int &ret = dp[pos][tot];
        if (ret != -1)
            return ret;
        
        long long p1 = INT_MAX;
        long long p2 = INT_MAX;
        
        if (coins[pos] <= tot) {
            p1 = 1 + (long long)DP(coins, n, pos, tot - coins[pos]);
        }
        
        p2 = DP(coins, n, pos + 1, tot);
        
        return ret = min(p1, p2);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof dp);
        int ans = DP(coins, coins.size(), 0, amount);
        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }
};
