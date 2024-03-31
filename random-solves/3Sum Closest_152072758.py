import sys

class Solution(object):
    def threeSumClosest(self, nums, target):
        ans = 0
        diff = sys.maxsize
        nums = sorted(nums)

        for i in range(0, len(nums)):
            j = i + 1
            k = len(nums) - 1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                d = abs(target - sum)
                
                if d == 0:
                    return sum
                
                if d < diff:
                    diff = d
                    ans = sum

                if sum <= target:
                    j = j + 1
                else:
                    k = k - 1
        
        return ans
