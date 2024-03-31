class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        dict = {}
        for num in nums:
            dict[num] = True
        
        cnt = 0
        for num in nums:
            if dict[num]:
                dict[num] = False
                curr = 1
                starter = num
                sub = 1
                add = 1
                
                while (starter + add) in dict:
                    dict[starter + add] = False
                    add += 1
                    curr += 1
                    
                while (starter - sub) in dict:
                    dict[starter - sub] = False
                    sub += 1
                    curr += 1
                    
                cnt = max(cnt, curr)
                
        return cnt
