class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        skip = {}
        
        i = 0
        for c in s:
            if c == '(':
                stack.append((c, i))
            elif c == ')':
                if len(stack) != 0:
                    stack.pop()
                else:
                    skip[i] = True
             
            i += 1
            
        while len(stack):
            _, i = stack[-1]
            stack.pop()
            skip[i] = True
        
        res_s = ""
        for i in range(len(s)):
            if i not in skip:
                res_s += s[i]
                
        return res_s
            
        
                
