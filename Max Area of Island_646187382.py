class Solution:
    def is_valid(self, m, n, r, c) -> bool:
        return 0 <= r and r < m and 0 <= c and c < n
    
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        
        m = len(grid)
        n = len(grid[0])
        
        ans = 0
        for i in range(m):
            for j in range(n):
                # print(i, j)
                if grid[i][j] != 0:
                    cnt = 0
                    q = []
                    q.append((i, j))
                    grid[i][j] = 0
                    
                    while len(q) != 0:
                        ux, uy = q.pop(0)
                        cnt += 1
                        
                        for it in range(4):
                            vx = ux + dx[it]
                            vy = uy + dy[it]
                            
                            if self.is_valid(m, n, vx, vy):
                                if grid[vx][vy] == 1:
                                    grid[vx][vy] = 0
                                    q.append((vx, vy))
                    
                    ans = max(ans, cnt)
                    
        return ans
                                
