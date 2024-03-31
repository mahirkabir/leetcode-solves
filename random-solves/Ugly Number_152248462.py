class Solution:
    def div(self, num, d):
        while num > 0:
            if num % d == 0:
                num = num / d
            else:
                return num
        
        return num

    def isUgly(self, num):
        if num < 1:
            return False
        
        if num == 1:
            return True

        num = self.div(num, 2)
        num = self.div(num, 3)
        num = self.div(num, 5)

        return num == 1
