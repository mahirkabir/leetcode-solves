# 3:32
class Solution:
    def maxArea(self, arr: List[int]) -> int:
        ans = -(2 ** 31)
        st = 0
        en = len(arr) - 1
        
        while st < en:
            mn = min(arr[st], arr[en])
            ans = max(ans, (en - st) * mn)
            if mn == arr[st]:
                st += 1
            else:
                en -= 1
            
        return ans
