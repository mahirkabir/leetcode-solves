class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zidx = -1
        nzidx = -1
        for i in range(0, len(nums)):
            if nums[i] != 0:
                if zidx != -1 and i > zidx:
                    t = nums[i]
                    nums[i] = 0
                    nums[zidx] = t
                    zidx += 1
                    if nums[zidx] != 0:
                        zidx = i
            else:
                if zidx == -1:
                    zidx = i
            
