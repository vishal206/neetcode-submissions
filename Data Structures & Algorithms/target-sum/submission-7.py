class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        
        dp = [defaultdict(int) for _ in range(len(nums)+1)]

        dp[0][0] = 1 #there is 1 way to make sum 0 with 0 element

        for i in range(len(nums)):
            for cur_sum, count in dp[i].items(): #getting key value pair
                dp[i+1][cur_sum+nums[i]] += count
                dp[i+1][cur_sum-nums[i]] += count
        return dp[len(nums)][target]