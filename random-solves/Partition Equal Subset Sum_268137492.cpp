class Solution {
public:
    int W;
    int N;
    int dp[200 + 1][10000 + 1][2 + 1];
    vector<int> arr;
    
    bool DP(int pos, int tot, int atleastOneNotTaken) {
        //cout << pos << " " << tot << " " << atleastOneNotTaken << endl;
        if(pos == N) {
            if(atleastOneNotTaken != 0) {
                return tot == W;
            }
            
            return false;
        }
        
        if(tot == W) {
            return atleastOneNotTaken != 0;
        }
        
        int &ret = dp[pos][tot][atleastOneNotTaken];
        
        if(ret != -1)
            return ret;
        
        bool p1 = DP(pos + 1, tot, 1);
        bool p2 = false;
        
        if(tot + arr[pos] <= W)
            p2 = DP(pos + 1, tot + arr[pos], atleastOneNotTaken);
        
        return ret = p1 || p2;
    }
    
    bool canPartition(vector<int>& nums) {
        W = 0;
        N = nums.size();
        arr = nums;
        
        for(int i = 0; i < N; ++i)
            W += nums[i];
        
        if(W % 2 != 0)
            return false;
        
        W >>= 1;
        
        memset(dp, -1, sizeof dp);
        
        return DP(0, 0, 0);
    }
};
