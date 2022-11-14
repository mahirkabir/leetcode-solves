class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        st = 0
        en = 0
        
        res_st = 0
        res_en = 0
        
        dict = {}
        while en < len(s):
            print(s[en], "X")
            if s[en] in dict:
                print(s[en], dict[s[en]], "XX")
                if dict[s[en]] != -1:
                    old_idx = dict[s[en]]
                    for i in range(st, dict[s[en]] + 1):
                        dict[s[i]] = -1
                    st = old_idx + 1
                    # print(st, en)
                dict[s[en]] = en        
            else:
                dict[s[en]] = en
                if st == -1:
                    st = en
            
            if ans < en - st + 1:
                ans = en - st + 1
                res_st = st
                res_en = en
            print(st, en, "xxx")
            en += 1
        
        print(res_st, res_en)
        return ans
