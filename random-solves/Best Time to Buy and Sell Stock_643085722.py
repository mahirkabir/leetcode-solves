class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        
        buy = prices[0]
        sell = prices[1]
        profit = sell - buy
        
        for i in range(2, len(prices)):
            num = prices[i]
            
            if num < sell:
                if num < buy:
                    buy = num
                    sell = buy
            elif num > sell:
                if sell > buy:
                    sell = num
                    profit = max(profit, sell - buy)
                else:
                    profit = max(profit, num - sell)
                    buy = sell
                    sell = num
                    
        return max(profit, 0)
                    
        
        
