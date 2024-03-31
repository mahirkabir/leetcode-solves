class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dict2 = {}
        for c in magazine:
            if c not in dict2:
                dict2[c] = 0
            dict2[c] += 1
        
        for c in ransomNote:
            if c not in dict2 or dict2[c] == 0:
                return False
            else:
                dict2[c] -= 1
        
        return True
