class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        res = []
        for str in queries:
            st = 0
            res.append(True)
            its = 0
            itq = 0
            
            while its < len(str) and itq < len(pattern):
                if str[its] == pattern[itq]:
                    its += 1
                    itq += 1
                else:
                    if str[its].islower():
                        its += 1
                    else:
                        res[-1] = False
                        break
            
            if itq < len(pattern):
                res[-1] = False
            else:
                while its < len(str):
                    if not str[its].islower():
                        res[-1] = False
                        break
                    its += 1
                        
        return res
