class Solution:
    def mySqrt(self, x: int) -> int:
        lo = 0
        hi = x
        
        while lo < hi:
            mid = ceil((lo + hi) / 2)
            
            if mid * mid == x:
                return mid
            
            if mid * mid > x:
                hi = mid - 1
            else:
                lo = mid
                
        return lo
