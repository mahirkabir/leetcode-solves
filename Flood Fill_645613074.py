class Solution(object):
    def is_valid(self, m, n, vx, vy):
        return 0 <= vx and vx < m and 0 <= vy and vy < n
    
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        dx = [-1, 1, 0, 0]
        dy = [0, 0, 1, -1]
        
        q = []
        m = len(image)
        n = len(image[0])
        org_color = image[sr][sc]
        
        if org_color == newColor:
            return image
        
        image[sr][sc] = newColor
        
        q.append((sr, sc))
        
        while len(q) != 0:
            print(q)
            ur, uc = q.pop(0)
            
            for i in range(0, 4):
                vx = ur + dx[i]
                vy = uc + dy[i]
                
                if self.is_valid(m, n, vx, vy):
                    if image[vx][vy] == org_color:
                        image[vx][vy] = newColor
                        q.append((vx, vy))
                            
        return image
