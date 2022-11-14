class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
            
        nums.reverse()
        nums.append(0)
        nums.reverse()
        ans = 2 ** 31
        
        for st in range(1, len(nums)):
            hi = len(nums) - 1
            lo = st - 1
            
            curr = 2 ** 31
            while lo <= hi:
                mid = floor((lo + hi) / 2)
                tot = nums[mid] - nums[st - 1]
                
                if tot < target:
                    lo = mid + 1
                else:
                    # print(st, mid, "f")
                    curr = min(curr, mid - st + 1)
                    # print(st, mid, "s")
                    hi = mid - 1
                    
            ans = min(ans, curr)
            
        if ans == 2 ** 31:
            ans = 0
        return ans
            
