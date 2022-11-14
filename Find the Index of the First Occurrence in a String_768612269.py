class Solution:
    def strStr(self, hs: str, nd: str) -> int:
        hi = 0
        ni = 0
        st = -1
        
        while hi < len(hs):
            if hs[hi] == nd[ni]:
                if st == -1:
                    st = hi
                    
                hi += 1
                ni += 1
                
                if ni == len(nd):
                    return st
            else:
                hi = st + 1
                ni = 0
                while hi < len(hs) and hs[hi] != nd[ni]:
                    hi += 1
                    
                if hi + len(nd) - 1 >= len(hs):
                    break
                st = hi
                
        return -1
