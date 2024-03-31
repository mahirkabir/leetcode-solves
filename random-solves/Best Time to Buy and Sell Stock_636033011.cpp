class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        
        int lo = prices[0];
        int hi = lo;
        
        int ans = 0;
        for (int i = 1; i < n; i++)
            {
            if (prices[i] < lo)
                lo = hi = prices[i];
            else if (prices[i] > hi)
                hi = prices[i];
            
            ans = max (ans, hi - lo);
    
}
        return ans;
    }
};
