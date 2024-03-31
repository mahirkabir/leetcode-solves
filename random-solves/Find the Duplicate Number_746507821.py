class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums) - 1
        
        lo = 1
        hi = n
        
        ans = -1
        
        while lo <= hi:
            mid = floor((lo + hi) / 2)
            cnt = mid
            for i in range(n + 1):
                if nums[i] <= mid:
                    cnt -= 1
            
            if cnt < 0:
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        
        return ans
