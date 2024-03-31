class Solution:
    def get_pivot(self, nums):
        lo = 0
        hi = len(nums) - 1
        
        ans = hi
        while lo <= hi:
            mid = floor((lo + hi) / 2)
            if nums[mid] > nums[-1]:
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1
                
        return ans
    
    def find(self, nums, st, en, target):
        # print(nums, st, en, target)
        lo = st
        hi = en
        
        while lo <= hi:
            mid = floor((lo + hi) / 2)
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                hi = mid - 1
            else:
                lo = mid + 1
                
        return -1
    
    def search(self, nums: List[int], target: int) -> int:
        if nums[0] <= nums[-1]:
            nums.append(-1)
            
        pivot = self.get_pivot(nums)
        # print(pivot)
        if nums[-1] == -1:
            nums = nums[:-1]
        
        ans = self.find(nums, 0, pivot, target)
        if ans == -1 and pivot < len(nums) - 1:
            ans = self.find(nums, pivot + 1, len(nums) - 1, target)
            
        return ans            
        
