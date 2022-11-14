class Solution:
    def validPalindrome(self, s: str) -> bool:
        if s == s[::-1]:
            return True
        
        st = 0
        en = len(s) - 1
        
        while st < en:
            if s[st] == s[en]:
                st += 1
                en -= 1
                
            else:
                alt1 = s[:st] + s[st + 1:]
                if alt1 == alt1[::-1]:
                    return True
                
                alt2 = s[:en] + s[en + 1:]
                if alt2 == alt2[::-1]:
                    return True
                return False
                
        return True
