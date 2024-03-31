class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row = -1
        
        m = len(matrix) - 1
        n = len(matrix[0]) - 1
        lo = 0
        hi = m
        while lo <= hi:
            mid = floor((lo + hi) / 2)
            
            if matrix[mid][0] <= target and matrix[mid][-1] >= target:
                row = mid
                break
            elif matrix[mid][0] > target:
                hi = mid - 1
            elif matrix[mid][-1] < target:
                lo = mid + 1
        
        if row == -1:
            return False
        
        lo = 0
        hi = n
        while lo <= hi:
            mid = floor((lo + hi) / 2)
            
            if matrix[row][mid] == target:
                return True
            
            if matrix[row][mid] > target:
                hi = mid - 1
            else:
                lo = mid + 1
        
        return False
        
            
