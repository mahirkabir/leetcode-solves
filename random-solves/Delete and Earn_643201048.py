class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        dict = {}
        nums.sort()
        for num in nums:
            if num not in dict:
                dict[num] = 0
            dict[num] += 1
        
        nums = []
        for num in dict:
            nums.append(num)
            
        if len(nums) == 1:
            return nums[0] * dict[nums[0]]
        
        dp = {}
        dp[nums[0]] = nums[0] * dict[nums[0]]
        if nums[1] - nums[0] == 1:
            dp[nums[1]] = max(dp[nums[0]], nums[1] * dict[nums[1]])
        else:
            dp[nums[1]] = dp[nums[0]] + nums[1] * dict[nums[1]]
        
        for i in range(2, len(nums)):
            prev = nums[i - 1]
            if nums[i] - prev == 1:
                p1 = dp[prev]
                p2 = dp[nums[i - 2]] + nums[i] * dict[nums[i]]
                dp[nums[i]] = max(p1, p2)
            else:
                dp[nums[i]] = dp[nums[i - 1]] + nums[i] * dict[nums[i]]
        
        return dp[nums[-1]]
