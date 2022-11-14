class Solution:
    def DP(self, cost, n, dp) -> int:
        if n == len(cost):
            return 0
        elif n > len(cost):
            return 10000000
        
        if n in dp:
            return dp[n]
        
        p1 = cost[n] + self.DP(cost, n + 1, dp)
        p2 = cost[n] + self.DP(cost, n + 2, dp)
        
        dp[n] = min(p1, p2)
        return dp[n]
    
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = {}
        return min(self.DP(cost, 0, dp), self.DP(cost, 1, dp))
