class Solution:
    def rob(self, nums: List[int]) -> int:
        ns = len(nums)
        cache = [None]*(ns)

        def dp(n):
            if n>=ns:
                return 0
            if cache[n] is not None:
                return cache[n]
            
            cache[n] = max(nums[n]+dp(n+2),dp(n+1))

            return cache[n]
        
        return dp(0)