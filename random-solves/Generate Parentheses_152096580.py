class Solution:
    # def merge(self, a, b):
    #     l = (int)(len(a))
    #     left = a[:(int)(l/2)]
    #     right = a[-(int)(l/2):]
    #     return left + b + right

    def call(self, curr, n, l, r):
        if r > l:
            return
        if l == n:
            self.ans.append(curr + ")" * (n - r))
            return
        if r == n:
            self.ans.append("(" * (n - l) + curr)
            return

        self.call(curr + "(", n, l + 1, r)
        self.call(curr + ")", n, l, r + 1)
        self.call(curr + "()", n, l + 1, r + 1)

    def generateParenthesis(self, n):
        self.ans = []
        
        self.call("", n, 0, 0)
        self.ans = list(set(self.ans))
        return self.ans
