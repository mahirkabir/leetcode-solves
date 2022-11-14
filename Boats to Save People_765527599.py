class Solution:
    def numRescueBoats(self, arr: List[int], limit: int) -> int:
        arr.sort()
        print(arr)
        st = 0
        en = len(arr) - 1
        
        ans = 0
        while st <= en:
            if st == en:
                ans += 1
                break
            if arr[st] + arr[en] <= limit:
                st += 1
                en -= 1
            else:
                en -= 1
               
            ans += 1
            
        return ans
