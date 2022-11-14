class Solution:
    def balancedStringSplit(self, s: str) -> int:
        cnt = 0
        
        stack = [s[0]]
        for c in s[1:]:
            if len(stack) == 0:
                stack.append(c)
            elif c == stack[-1]:
                stack.append(c)
            else:
                stack.pop()
                if len(stack) == 0:
                    cnt += 1
                    
        return cnt
