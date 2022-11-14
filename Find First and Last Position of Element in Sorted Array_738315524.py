class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        ans = [-1, -1]
        
        lo = 0
        hi = len(nums) - 1
        
        while lo <= hi:
            mid = floor((lo + hi) / 2)
            
            if target == nums[mid]:
                ans[0] = mid
                hi = mid - 1
            elif target < nums[mid]:
                hi = mid - 1
            else:
                lo = mid + 1
        
        lo = 0
        hi = len(nums) - 1
        
        while lo <= hi:
            mid = floor((lo + hi) / 2)
            
            if target == nums[mid]:
                ans[1] = mid
                lo = mid + 1
            elif target < nums[mid]:
                hi = mid - 1
            else:
                lo = mid + 1
                
        return ans
