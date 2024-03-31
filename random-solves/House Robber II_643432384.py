class Solution:
    def DP(self, nums, curr, dp):
        if curr == len(nums):
            return 0
        
        if curr in dp:
            return dp[curr]
        
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        
        for i in range(2, len(nums)):
            p1 = nums[i] + dp[i - 2]
            p2 = dp[i - 1]
            dp[i] = max(p1, p2)
            
        return dp[len(nums) - 1]
    
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums[0], nums[1])
        
        dp = {}
        # print(nums[:len(nums) - 1])
        all_but_last = self.DP(nums[:len(nums) - 1], 0, dp)
        
        dp = {}
        # print(nums[1:])
        all_but_first = self.DP(nums[1:], 0, dp)
        
        print(str(all_but_last) + " " + str(all_but_first))
        return max(all_but_last, all_but_first)
