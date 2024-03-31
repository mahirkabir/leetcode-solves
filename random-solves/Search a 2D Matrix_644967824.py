class Solution:
    def get_row(self, matrix, target) -> int:
        m = len(matrix)
        n = len(matrix[0])
        
        lo = 0
        hi = m - 1
        
        while lo < hi:
            mid = int((lo + hi) / 2)
            if matrix[mid][0] <= target and matrix[mid][n - 1] >= target:
                return mid
            elif matrix[mid][0] > target:
                hi = mid - 1
            elif matrix[mid][n - 1] < target:
                lo = mid + 1
                
        return lo
    
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row = self.get_row(matrix, target)
        
        n = len(matrix[row])
        lo = 0
        hi = n - 1
        
        while lo < hi:
            mid = int((lo + hi) / 2)
            if matrix[row][mid] == target:
                return True
            elif matrix[row][mid] < target:
                lo = mid + 1
            else:
                hi = mid - 1
        
        return matrix[row][lo] == target
