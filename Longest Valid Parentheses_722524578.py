class Solution:
    def longestValidParentheses(self, s: str) -> int:
        sz = len(s)
        dp = [0]
        mx = 0
        for i in range(1, sz):
            dp.append(0)
            if s[i] == ')':
                if s[i - 1] == '(':
                    dp[i] = 2
                    if i - 2 >= 0:
                        dp[i] += dp[i - 2]
                else:
                    prev_sub_st = (i - 1) - dp[i - 1] + 1
                    if prev_sub_st < i - 1 and prev_sub_st - 1 >= 0 and s[prev_sub_st 
                        - 1] == '(':
                        dp[i] = dp[i - 1] + dp[prev_sub_st - 1] + 2
                        if prev_sub_st - 2 >= 0:
                            dp[i] += dp[prev_sub_st - 2]
                        
            mx = max(mx, dp[i])
            # print(dp)
            
        return mx
                        
        
