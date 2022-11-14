class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        left = m - 1
        right = n - 1
        pos = m + n - 1
        while left >= 0 or right >= 0:
            if left == -1:
                nums1[pos] = nums2[right]
                pos -= 1
                right -= 1
            elif right == -1:
                nums1[pos] = nums1[left]
                pos -= 1
                left -= 1
            elif nums1[left] < nums2[right]:
                nums1[pos] = nums2[right]
                pos -= 1
                right -= 1
            else:
                nums1[pos] = nums1[left]
                pos -= 1
                left -= 1
