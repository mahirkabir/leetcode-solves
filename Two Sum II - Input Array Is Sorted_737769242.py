class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        sz = len(numbers)
        for it in range(0, sz - 1):
            lo = it + 1
            hi = sz - 1
            
            while lo <= hi:
                mid = ceil((lo + hi) / 2)
                # print(numbers[it], numbers[mid])
                if numbers[it] + numbers[mid] == target:
                    return [it + 1, mid + 1]
                
                if numbers[it] + numbers[mid] > target:
                    hi = mid - 1
                else:
                    lo = mid + 1        
