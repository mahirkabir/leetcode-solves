class Solution:
    def is_valid(self, m, n, r, c):
        return 0 <= r and r < m and 0 <= c and c < n
    
    def get_distance(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])
        
        dist = []
        
        # print(mat[0][0], dist[0][0], "$$")
        for i in range(m):
            dist.append([])
            for j in range(n):
                dist[i].append(100000)
        
        
        if mat[0][0] == 2:
            dist[0][0] = 0
            
        for i in range(m):
            for j in range(n):
                # print(i, j, dist[i][j], "prev")
                if mat[i][j] == 2:
                    dist[i][j] = 0
                elif mat[i][j] == 0:
                    dist[i][j] = 100000
                elif mat[i][j] == 1:
                    if self.is_valid(m, n, i - 1, j):
                        dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j])
                    if self.is_valid(m, n, i, j - 1):
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1)
                        
                # print(i, j, dist[i][j], "now")
                
        
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                # print(i, j, "$$$")
                if mat[i][j] == 2:
                    dist[i][j] = 0
                elif mat[i][j] == 0:
                    dist[i][j] = 100000
                elif mat[i][j] == 1:
                    if self.is_valid(m, n, i + 1, j):
                        dist[i][j] = min(dist[i + 1][j] + 1, dist[i][j])
                    if self.is_valid(m, n, i, j + 1):
                        dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1)
                        
        return dist
    
    def _orangesRotting(self, grid: List[List[int]]) -> int:
        dist = self.get_distance(grid)
        
        m = len(grid)
        n = len(grid[0])
        
        ans = -100000
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    if dist[i][j] >= 100000:
                        print(i, j)
                        return -1
                    
                    ans = max(ans, dist[i][j])
         
        if ans == -100000:
            return 0
        return ans
    
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        
        ans = -100000
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    q = []
                    q.append((i, j))
                    color = {}
                    dist = {}
                    color[i, j] = 1
                    dist[i, j] = 0
                    
                    curr = -1
                    while len(q) != 0:
                        ur, uc = q.pop(0)
                        
                        for it in range(4):
                            vr, vc = ur + dx[it], + uc + dy[it]
                            
                            if self.is_valid(m, n, vr, vc):
                                if grid[vr][vc] == 1 and ((vr, vc) not in color or 
                                    color[vr, vc] == 0):
                                    color[vr, vc] = 1
                                    dist[vr, vc] = dist[ur, uc] + 1
                                    q.append((vr, vc))
                                elif grid[vr][vc] == 2:
                                    curr = dist[ur, uc] + 1
                                    break
                                    
                        if curr != -1:
                            break
                                    
                    if curr == -1:
                        return -1
                    
                    ans = max(ans, curr)
                    
        if ans == -100000:
            return 0
        return ans
