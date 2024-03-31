class Solution:
    def check(self, grid, ch):
        for row in range(3):
            ret = True
            for col in range(3):
                ret &= (grid[row][col] == ch)
            if ret:
                # print("1")
                return True
            
        for col in range(3):
            ret = True
            for row in range(3):
                ret &= (grid[row][col] == ch)
            if ret:
                # print("2")
                # print(grid)
                return True
            
        ret = True
        for i in range(3):
            ret &= (grid[i][i] == ch)
        if ret:
            # print("3")
            return True
        
        ret = True
        for i in range(3):
            ret &= (grid[i][2 - i] == ch)
        if ret:
            # print("4")
            return True
        
        return False
                    
    
    def tictactoe(self, moves: List[List[int]]) -> str:
        grid = []
        for i in range(3):
            row = []
            for j in range(3):
                row.append('-')
            grid.append(row)
        
        
        # print(grid)
        for i in range(len(moves)):
            # print(i, "i")
            r, c = moves[i][0], moves[i][1]
            if i % 2 == 0:
                grid[r][c] = 'x'
            else:
                grid[r][c] = 'o'
                
            if self.check(grid, 'x'):
                return "A"
            elif self.check(grid, 'o'):
                return "B"
            elif i == 8:
                return "Draw"
            
        return "Pending"
