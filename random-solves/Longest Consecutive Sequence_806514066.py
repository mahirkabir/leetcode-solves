class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        mp = {}
        
        for num in nums:
            mp[num] = 1
            
        res = 0
        for num in nums:
            n = num
            val = mp[num]
            
            if val == 0:
                continue
                
            while n - 1 in mp and mp[n - 1] == 1:
                    val = val + 1
                    n = n - 1
                    mp[n] = 0
                    
            n = num
            while n + 1 in mp and mp[n + 1] == 1:
                    val = val + 1
                    n = n + 1
                    mp[n] = 0
                    
            mp[num] = 0
                
            res = max(res,val)
        return res
