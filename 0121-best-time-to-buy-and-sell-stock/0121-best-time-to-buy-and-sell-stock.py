class Solution(object):
    def maxProfit(self, prices):
        profit = 0
        buy = prices[0]

        for i in range(len(prices)):
            if buy > prices[i]:
                buy = prices[i]

            profit = max(profit, prices[i] - buy)

        return profit