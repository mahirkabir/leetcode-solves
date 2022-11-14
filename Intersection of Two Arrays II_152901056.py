class Solution:
    def intersect(self, nums1, nums2):
        ans = []
        
        nums1.sort()
        nums2.sort()

        na = len(nums1)
        nb = len(nums2)

        i = 0
        j = 0

        while i < na and j < nb:
            if nums1[i] == nums2[j]:
                ans.append(nums1[i])
                i = i + 1
                j = j + 1
            elif nums1[i] > nums2[j]:
                j = j + 1
            else:
                i = i + 1

        return ans
