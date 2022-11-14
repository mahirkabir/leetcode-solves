class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        
        houses_sz = len(houses)
        heaters_sz = len(heaters)
        lo = 0
        hi = 1000 ** 3

        ans = 1000 ** 3
        while lo <= hi:
            mid = floor((lo + hi) / 2)
            heater_pos = 0
            possible = True
            for i in range(0, houses_sz):
                curr_possible = False
                while heater_pos < heaters_sz:
                    if abs(heaters[heater_pos] - houses[i]) <= mid:
                        curr_possible = True
                        break
                    heater_pos += 1
                if curr_possible == False:
                    possible = False
                    break
            
            if possible:
                ans = min(ans, mid)
                hi = mid - 1
            else:
                lo = mid + 1
            
            
        return ans
