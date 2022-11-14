class Solution:
    def firstUniqChar(self, s: str) -> int:
        d = {}
        for c in s:
            if c not in d:
                d[c] = 0
            d[c] += 1
            
        for i in range(len(s)):
            c = s[i]
            if d[c] == 1:
                return i
        return -1
            
        
