class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        pos = 0
        
        while True:
            str = strs[0]
            if pos >= len(str):
                return str[:pos]
            ch = str[pos]
            
            for str in strs[1:]:
                if pos >= len(str):
                    return str[:pos]
                if str[pos] != ch:
                    return str[:pos]
            
            pos += 1
            
        
                    
