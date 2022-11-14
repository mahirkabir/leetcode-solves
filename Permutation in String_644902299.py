class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        dict1 = {}
        for c in s1:
            if c not in dict1:
                dict1[c] = 0
            dict1[c] += 1
        
        st = 0
        en = 0
        dict2 = {}
        while en < len(s2):
            if s2[en] not in dict1:
                while st != en:
                    dict2[s2[st]] -= 1
                    st += 1
                st += 1
            else:
                if s2[en] not in dict2:
                    dict2[s2[en]] = 0
                dict2[s2[en]] += 1
                
                if dict2[s2[en]] > dict1[s2[en]]:
                    while s2[st] != s2[en]:
                        dict2[s2[st]] -= 1
                        st += 1
                    dict2[s2[st]] -= 1
                    st += 1
                else:
                    if en - st + 1 == len(s1):
                        print(dict2, st, en)
                        return True
            en += 1
        
        return False
