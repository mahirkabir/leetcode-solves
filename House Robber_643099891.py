class Solution:
    def DP(self, nums, curr, dp) -> int:
        if curr >= len(nums):
            return 0
        
        if curr in dp:
            return dp[curr]
        
        p1 = nums[curr] + self.DP(nums, curr + 2, dp)
        p2 = self.DP(nums, curr + 1, dp)
    
        dp[curr] = max(p1, p2)
        return dp[curr]
            
    
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums[0], nums[1])
        
        dp = {}
        return self.DP(nums, 0, dp)
