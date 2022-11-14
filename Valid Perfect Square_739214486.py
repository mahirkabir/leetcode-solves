class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        lo = 0
        hi = 46341
        
        while lo <= hi:
            mid = floor((lo + hi) / 2)
            if mid * mid == num:
                return True
            elif mid * mid < num:
                lo = mid + 1
            else:
                hi = mid - 1
        
        return False
        
        
