class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        lo = 1
        hi = len(arr) - 1
        
        while lo < hi:
            mid = ceil((lo + hi) / 2)
            
            if arr[mid - 1] < arr[mid]:
                lo = mid
            else:
                hi = mid - 1
        
        return lo
