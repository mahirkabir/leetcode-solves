class Solution:
    def maximumUnits(self, arr: List[List[int]], tot: int) -> int:
        arr.sort(reverse=True, key = lambda x: x[1])
        ans = 0
        for elm in arr:
            if tot >= elm[0]:
                tot -= elm[0]
                ans += elm[0] * elm[1]
            else:
                ans += tot * elm[1]
                break
                
        return ans
