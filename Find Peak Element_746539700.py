class Solution:
    def findPeakElement(self, arr: List[int]) -> int:
        """if len(arr) == 1:
            return 0
        elif len(arr) == 2:
            if arr[0] > arr[1]:
                return 0
            return 1
        """
        
        int_min = -(2 ** 31) - 1
        
        arr = [int_min] + arr + [int_min]
        n = len(arr)
        
        lo = 0
        hi = n - 1
        
        while lo <= hi:
            mid = floor((lo + hi) / 2)
            
            # print(mid, arr[mid])
            
            if mid == 0:
                lo = mid + 1
                continue
            elif mid == n - 1:
                hi = mid - 1
                continue
            
            # print(arr[mid - 1], arr[mid], arr[mid + 1])
            
            if arr[mid - 1] < arr[mid] and arr[mid] > arr[mid + 1]:
                return mid - 1
            
            if arr[mid - 1] < arr[mid] and arr[mid] < arr[mid + 1]:
                lo = mid + 1
            else:
                hi = mid - 1
                
        
