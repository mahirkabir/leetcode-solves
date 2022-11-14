class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        cnt = 0
        
        rows = []
        
        for r in range(n):
            arr = []
            for i in range(n):
                arr.append(grid[r][i])
            rows.append(arr)
            
        cols = []
        for c in range(n):
            arr = []
            for i in range(n):
                arr.append(grid[i][c])
            cols.append(arr)
        
        for i in range(n):
            for j in range(n):
                if rows[i] == cols[j]:
                    cnt += 1
        
        return cnt
