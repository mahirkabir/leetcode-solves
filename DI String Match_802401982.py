class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        lo = 0
        hi = len(s)
        
        res = []
        
        for c in s:
            if c == 'I':
                res.append(lo)
                lo += 1
            else:
                res.append(hi)
                hi -= 1
                
        res.append(lo)
        
        return res
