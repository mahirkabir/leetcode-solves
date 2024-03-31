class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        currSum = 0
        maxSum = -1000000000
        sz = len(nums)
        
        for i in range(sz):
            num = nums[i]
            currSum += num
            
            if currSum > maxSum:
                maxSum = currSum
            if currSum < 0:
                currSum = 0
                
        return maxSum
