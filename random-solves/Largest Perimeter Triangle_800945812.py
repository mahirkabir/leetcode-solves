class Solution:
    def largestPerimeter(self, org_nums: List[int]) -> int:
        org_nums.sort()
        
        for add in range(len(org_nums), 2, -1):
            nums = org_nums[:add]
            s1 = 0
            s2 = 0
            for i in range(len(nums) - 3, -1, -1):
                if nums[i] + nums[-2] > nums[-1]:
                    s1 = nums[i] + nums[-2] + nums[-1]
                    break

            for i in range(len(nums) - 4, -1, -1):
                if nums[i] + nums[-3] > nums[-1]:
                    s2 = nums[i] + nums[-3] + nums[-1]
                    break
                    
            if max(s1, s2) != 0:
                return max(s1, s2)
                
        return 0
        
