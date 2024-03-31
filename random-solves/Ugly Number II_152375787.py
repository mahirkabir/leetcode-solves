class Solution:
    def nthUglyNumber(self, n):
        i2 = 0
        i3 = 0
        i5 = 0

        ans = [1]
        cnt = 1

        while cnt < n:
            m2 = ans[i2] * 2
            m3 = ans[i3] * 3
            m5 = ans[i5] * 5

            MIN = min(m2, min(m3, m5))

            ans.append(MIN)
            cnt = cnt + 1

            i2 = i2 + int(MIN == m2)
            i3 = i3 + int(MIN == m3)
            i5 = i5 + int(MIN == m5)

        return ans[-1]
