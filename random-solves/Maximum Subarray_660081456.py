class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sz = len(nums)
        
        dp = [nums[0]]
        maxSum = nums[0]
        
        for i in range(1, sz):
            dp.append(max(nums[i], nums[i] + dp[i - 1]))
            maxSum = max(maxSum, dp[i])
            
        return maxSum
