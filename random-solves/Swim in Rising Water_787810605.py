class Solution:
    def get_max(self, grid):
        ans = grid[0][0]
        for line in grid:
            for cell in line:
                ans = max(ans, cell)
        return ans
    
    def is_valid(self, x, y, m, n):
        return x >= 0 and y >= 0 and x < m and y < n
    
    def traversable(self, grid, t):
        """Check if grid can be traversed at time t"""
        m = len(grid)
        n = len(grid[0])
        
        queue = [(0, 0)]
        color = {(0, 0): True}
        
        if grid[0][0] > t:
            return False
        if m == 0 and n == 0:
            return True
        
        while len(queue) > 0:
            ur, uc = queue.pop(0)
            dx = [0, 0, 1, -1]
            dy = [1, -1, 0, 0]
            
            for i in range(0, 4):
                vr = ur + dx[i]
                vc = uc + dy[i]
                
                if self.is_valid(vr, vc, m, n) and grid[vr][vc] <= t:
                    if (vr, vc) not in color:
                        if vr == m - 1 and vc == n - 1:
                            return True
                        queue.append((vr, vc))
                        color[(vr, vc)] = 1
    
        return False
    
    def swimInWater(self, grid: List[List[int]]) -> int:
        mx = self.get_max(grid)
        ans = mx
        lo = 0
        hi = mx
        
        while lo <= hi:
            mid = floor((lo + hi) / 2)
            if self.traversable(grid, mid):
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        
        return ans
