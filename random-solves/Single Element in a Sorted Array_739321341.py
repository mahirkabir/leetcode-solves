class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        lo = 0
        hi = len(nums) - 1
        
        idx = -1
        while lo < hi:
            mid = floor((lo + hi) / 2)
            # print(lo, hi, mid)
            if mid % 2 == 1:
                mid -= 1
            
            if nums[mid] == nums[mid + 1]:
                lo = mid + 2
            else:
                idx = mid
                hi = mid - 1
        
        return nums[idx]
