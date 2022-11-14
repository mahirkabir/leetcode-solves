class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dict1 = {}
        dict2 = {}
        
        for num in nums1:
            if num not in dict1:
                dict1[num] = 0
            dict1[num] += 1
            
        for num in nums2:
            if num not in dict2:
                dict2[num] = 0
            dict2[num] += 1
            
        ans = []
        for num in dict1:
            if num in dict2:
                freq = min(dict1[num], dict2[num])
                while freq > 0:
                    ans.append(num)
                    freq -= 1
        
        return ans
