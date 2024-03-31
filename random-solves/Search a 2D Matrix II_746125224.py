class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        
        for i in range(m):
            row = matrix[i]
            
            lo = 0
            hi = n - 1
            
            while lo <= hi:
                mid = floor((lo + hi) / 2)
                if row[mid] == target:
                    return True
                
                if row[mid] > target:
                    hi = mid - 1
                else:
                    lo = mid + 1
            
        return False
