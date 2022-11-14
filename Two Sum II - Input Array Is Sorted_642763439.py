class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        st = 0
        en = len(numbers) - 1
        while(st < en):
            if numbers[st] + numbers[en] == target:
                return [st + 1, en + 1]
            elif numbers[st] + numbers[en] > target:
                en -= 1
            else:
                st += 1
