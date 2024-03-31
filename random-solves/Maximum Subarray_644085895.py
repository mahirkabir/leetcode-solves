class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = -100000
        curr = 0
        mx = ans
        for num in nums:
            mx = max(mx, num)
            if curr + num < 0:
                curr = 0
            else:
                curr += num
                
            ans = max(ans, curr)
            
        if ans == 0:
            return mx
        return ans
