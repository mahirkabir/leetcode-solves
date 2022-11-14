class Solution:
    def is_valid(self, m, n, r, c):
        return 0 <= r and r < m and 0 <= c and c < n
    
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])
        
        dist = []
        
        # print(mat[0][0], dist[0][0], "$$")
        for i in range(m):
            dist.append([])
            for j in range(n):
                dist[i].append(100000)
        
        
        if mat[0][0] == 0:
            dist[0][0] = 0
            
        # print(mat[0][0], dist[0][0], "$$")
            
        
        # dx = [-1, 1, 0, 0]
        # dy = [0, 0, -1, 1]
        
        for i in range(m):
            for j in range(n):
                # print(i, j, dist[i][j], "prev")
                if mat[i][j] == 0:
                    dist[i][j] = 0
                else:
                    if self.is_valid(m, n, i - 1, j):
                        dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j])
                    if self.is_valid(m, n, i, j - 1):
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1)
                        
                # print(i, j, dist[i][j], "now")
                
        """for i in range(m):
            for j in range(n - 1, 0, -1):
                # print(i, j, dist[i][j], "prev")
                if mat[i][j] == 0:
                    dist[i][j] = 0
                else:
                    if self.is_valid(m, n, i - 1, j):
                        dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j])
                    if self.is_valid(m, n, i, j + 1):
                        dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1)
                        
        for i in range(m - 1, 0, -1):
            for j in range(n):
                if mat[i][j] == 0:
                    dist[i][j] = 0
                else:
                    if self.is_valid(m, n, i + 1, j):
                        dist[i][j] = min(dist[i + 1][j] + 1, dist[i][j])
                    if self.is_valid(m, n, i, j - 1):
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1)"""          
                                 
        
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                # print(i, j, "$$$")
                if mat[i][j] == 0:
                    dist[i][j] = 0
                else:
                    if self.is_valid(m, n, i + 1, j):
                        dist[i][j] = min(dist[i + 1][j] + 1, dist[i][j])
                    if self.is_valid(m, n, i, j + 1):
                        dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1)
                        
        return dist
