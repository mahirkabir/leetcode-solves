class Solution:
    def has_duplicate(self, board, root):
        dict = {}
        # print("------------")
        for i in range(0, 3):
            for j in range(0, 3):
                r = root[0] + i
                c = root[1] + j
                # print(r, c, "$$$")
                if board[r][c] != "." and board[r][c] in dict:
                    # print(r, c, "***")
                    # print(dict[board[r][c]], "XXX")
                    return False
                dict[board[r][c]] = r, c
                
        return True
    
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for r in range(0, 9):
            dict = {}
            for c in range(0, 9):
                if board[r][c] != "." and board[r][c] in dict:
                    return False
                dict[board[r][c]] = True
        
        for c in range(0, 9):
            dict = {}
            for r in range(0, 9):
                if board[r][c] != "." and board[r][c] in dict:
                    return False
                dict[board[r][c]] = True
        
        """00 01 02 03 04 05
        10 11 12 13 14 15
        20 21 22 23 24 25
        30 31 32 33 34 35
        40 41 42 43 44 45
        50 51 52 53 54 55"""
        
        roots = [[0, 0], [0, 3], [0, 6],
                [3, 0], [3, 3], [3, 6],
                [6, 0], [6, 3], [6, 6]]
        
        for root in roots:
            if self.has_duplicate(board, root) == False:
                return False
            
        return True
