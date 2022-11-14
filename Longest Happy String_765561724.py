class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        arr = [(a, 'a'), (b, 'b'), (c, 'c')]
        # print(arr)
        arr.sort(key = lambda x: x[0])
        (a, cha), (b, chb), (c, chc) = arr[0], arr[1], arr[2]
        # print((a, cha), (b, chb), (c, chc))
        
        ans = ""
        ans += (cha + chb + chc) * a
        b -= a
        c -= a
        # print(ans)
        
        ans += (chb + chc) * b
        c -= b
        # print(ans)
        
        if ans == "":
            ans = chc * 2
        else:
            idx = 0
            while idx < len(ans) and c > 0:
                # print(ans, idx, ans[idx])
                if ans[idx] == cha or ans[idx] == chb:
                    if c > 1 and (idx == 0 or ans[idx - 1] != chc):
                        # print(ans)
                        ans = ans[:idx] + chc * 2 + ans[idx:]
                        # print(ans)
                        idx += 3
                        c -= 2
                    else:
                        # print(ans)
                        ans = ans[:idx] + chc + ans[idx:]
                        # print(ans)
                        idx += 2
                        c -= 1
                else:
                    # print(ans)
                    # ans = ans[:idx] + chc + ans[idx:]
                    # print(ans)
                    idx += 1
                    # c -= 1
                
        if c > 0 and ans != chc * 2:
            ans += chc
        return ans
