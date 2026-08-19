class Solution:
    def climbStairs(self, n: int) -> int:
        cache = [None] * (n+1)

        def dp(n):

            if n == 0:
                return 1
            elif n<0:
                return 0

            if cache[n]:
                return cache[n]
            
            cache[n] = dp(n-1) + dp(n-2)
            return cache[n]
        
        return dp(n)
