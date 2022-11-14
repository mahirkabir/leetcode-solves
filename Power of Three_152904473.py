import math

class Solution:
    def isPowerOfThree(self, n):
        if n < 1:
            return False
        ans = math.log(n, 3)
        #print("%d %.15f" % (math.ceil(ans), ans))
        #print(math.ceil(ans) - ans)
        return math.ceil(ans) - ans < 0.000000000000005
