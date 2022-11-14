class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        cnt = 0
        m = len(grid)
        n = len(grid[0])
        
        dx = [1, -1, 0, 0]
        dy = [0, 0, -1, 1]
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    cnt += 1
                    queue = [(i, j)]
                    grid[i][j] = '0'
                    while len(queue) > 0:
                        ui, uj = queue.pop(0)
                        for k in range(4):
                            vi = ui + dx[k]
                            vj = uj + dy[k]
                            
                            if vi >= 0 and vj >= 0 and vi < m and vj < n and 
                                grid[vi][vj] == '1':
                                queue.append((vi, vj))
                                grid[vi][vj] = '0'
        
        return cnt
