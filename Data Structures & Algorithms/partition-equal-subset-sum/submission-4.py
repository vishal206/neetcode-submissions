class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2:
            return False
        
        dp = set() # have a list of sum of the subsets
        dp.add(0)
        target = sum(nums) // 2

        for i in range(len(nums)):
            nextDp = set()
            for t in dp:
                nextDp.add(t)
                nextDp.add(t+nums[i])
            dp = nextDp
        
        return target in dp
            
        
            

