class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        # print(num, k)
        monotonic_stack = [ord(num[0]) - ord('0')]
        for c in num[1:]:
            ci = ord(c) - ord('0')
            top = monotonic_stack[-1]
            
            if ci >= top:
                monotonic_stack.append(ci)
            else:
                while k > 0 and ci < top:
                    monotonic_stack.pop()
                    k -= 1          
                    if len(monotonic_stack) == 0:
                        break
                    
                    top = monotonic_stack[-1]
                    
                monotonic_stack.append(ci)
        
        while k > 0 and len(monotonic_stack) != 0:
            monotonic_stack.pop()
            k -= 1
        
        # print(monotonic_stack)
        ret = ""
        for n in monotonic_stack:
            if ret == "" and n == 0:
                continue
            ret += chr(n + ord('0'))
         
        if ret == "":
            ret = "0"
        
        return ret
