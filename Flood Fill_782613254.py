class Solution:
    def isValid(self, x, y, m, n):
        return x >= 0 and y >= 0 and x < m and y < n
    
    def floodFill(self, color: List[List[int]], sr: int, sc: int, newColor: int) -> 
        List[List[int]]:
        m = len(color)
        n = len(color[0])
        
        org = color[sr][sc]
        if org == newColor:
            return color
        
        dx = [-1, 1, 0, 0]
        dy = [0, 0, 1, -1]
        
        queue = [(sr, sc)]
        color[sr][sc] = newColor
        
        while len(queue) > 0:
            ux, uy = queue.pop(0)
            
            for i in range(4):
                vx = ux + dx[i]
                vy = uy + dy[i]
                
                if self.isValid(vx, vy, m, n) and color[vx][vy] == org:
                    queue.append((vx, vy))
                    color[vx][vy] = newColor
                    
        return color
