class Solution(object):
    def fib(self, n):
        if n == 2 or n ==1:
            return 1
        if n == 0:
            return 0
        
        x = 1
        y = 1
        
        while n-3:
            x = x + y
            y = x - y
            n -= 1
            
        return x+y