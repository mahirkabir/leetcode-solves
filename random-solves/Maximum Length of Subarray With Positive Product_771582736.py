class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        arr = []
        st = -1
        en = -1
        ans = 0
        for i in range(len(nums)):
            num = nums[i]
            if num == 0:
                if st == -1:
                    continue
                if len(arr) %2 == 0: # already positive
                    ans = max(ans, en - st + 1)
                else:
                    a = arr[0] - st + 1
                    c = en - arr[-1] + 1
                    b = a + c - 1
                    
                    
                    d = min([a, b, c])
                    ans = max(ans, en - st + 1 - d)
                
                st = -1
                en = -1
                arr = []
            else:
                if st == -1:
                    st = i
                    en = i
                else:
                    en = i
                
                if num < 0:
                    arr.append(i)
        
        # print(arr, ans, st, en)
        if st == -1:
            return ans
        
        if len(arr) %2 == 0: # already positive
            ans = max(ans, en - st + 1)
        else:
            a = arr[0] - st + 1
            c = en - arr[-1] + 1
            b = a + c - 1


            d = min([a, b, c])
            ans = max(ans, en - st + 1 - d)
                    
        return ans
