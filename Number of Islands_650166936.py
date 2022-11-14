class Solution:
    def DFS(self, r, c, grid):
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        
        m = len(grid)
        n = len(grid[0])
        
        def is_valid(r, c):
            return 0 <= r and r < m and 0 <= c and c < n
        
        for i in range(4):
            vr = r + dx[i]
            vc = c + dy[i]
            
            if is_valid(vr, vc):
                if grid[vr][vc] == '1':
                    grid[vr][vc] = 'X'
                    self.DFS(vr, vc, grid)
    
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        cnt = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    grid[i][j] == 'X'
                    self.DFS(i, j, grid)
                    cnt += 1
                    
        return cnt
