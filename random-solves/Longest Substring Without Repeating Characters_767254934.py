class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        d = {s[0]: 1}
        
        st = 0
        en = 1
        ans = 1
        curr = 1
        
        while en < len(s):
            c = s[en]
            if c in d and d[c] == 1:
                while d[c] == 1:
                    cc = s[st]
                    d[cc] -= 1
                    curr -= 1
                    st += 1
                    # print(cc, st, curr, d)
                    
            d[c] = 1
            curr += 1
            # print(d, st, en, s[st:en + 1], curr)
            en += 1
            ans = max(ans, curr)
        
        return ans
