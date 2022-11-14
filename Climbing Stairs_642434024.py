class Solution:
    def DP(self, n, dict) -> int:
        if n == 0:
            return 1
        elif n < 0:
            return 0
        
        if n in dict:
            return dict[n]
        
        p1 = self.DP(n - 1, dict)
        p2 = self.DP(n - 2, dict)
        
        dict[n] = p1 + p2
        
        return p1 + p2
    
    def climbStairs(self, n: int) -> int:
        dict = {}
        return self.DP(n, dict)
