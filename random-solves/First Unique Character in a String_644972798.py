class Solution:
    def firstUniqChar(self, s: str) -> int:
        dict = {}
        for i in range(0, len(s)):
            c = s[i]
            if c in dict:
                dict[c] = -1
            else:
                dict[c] = i
        
        for c in dict:
            if dict[c] != -1:
                return dict[c]
        return -1
