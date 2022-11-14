class Solution:
    def listToInt(self, lst) -> int:
        num = 0
        
        for curr in lst:
            num = (num * 10) + curr
        
        return num
    
    def intToList(self, num):
        if num == 0:
            return [0]
        
        nums = []
        
        while num > 0:
            d = int(num % 10)
            nums.append(d)
            num = int(num / 10)
        
        nums.reverse()
        
        return nums
            
    
    def DP(self, first, second, nums, n, dp) -> int:
        print(nums, self.listToInt(nums), first, second)
        if second == n:
            return self.listToInt(nums)
        
        if first in dp and second in dp[first]:
            return dp[first][second]
        
        p1 = 0
        p2 = 0
        p3 = 0
        
        if (nums[first] % 2 == nums[second] % 2) and nums[first] < nums[second]:
            new_nums = nums
            tmp_first = nums[first]
            tmp_second = nums[second]
            new_nums[first] = tmp_second
            new_nums[second] = tmp_first
            p1 = self.DP(first + 1, first + 2, new_nums, n, dp)
            
        p2 = self.DP(first, second + 1, nums, n, dp)
        p3 = self.DP(first + 1, first + 2, nums, n, dp)
        
        ret = max(p1, max(p2, p3))
        if first not in dp:
            dp[first] = {}
            
        dp[first][second] = ret
        return ret
    
    def _largestInteger(self, num: int) -> int:
        nums = self.intToList(num)
        
        n = len(nums)
        if n == 1:
            return num
        
        dp = {}
        return self.DP(0, 1, nums, n, dp)
    
    def largestInteger(self, num: int) -> int:
        nums = self.intToList(num)
        
        n = len(nums)
        if n <= 1:
            return num
        
        odds = []
        evens = []
        
        for curr in nums:
            if curr % 2 == 0:
                evens.append(curr)
            else:
                odds.append(curr)
                
        odds.sort()
        odds.reverse()
        evens.sort()
        evens.reverse()
        
        odd_it = 0
        even_it = 0
        
        new_nums = []
        for curr in nums:
            if curr % 2 == 0:
                new_nums.append(evens[even_it])
                even_it += 1
            else:
                new_nums.append(odds[odd_it])
                odd_it += 1
        
        return self.listToInt(new_nums)
