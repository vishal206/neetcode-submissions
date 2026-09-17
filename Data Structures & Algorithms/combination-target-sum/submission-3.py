class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        curComb = []
        combs = []

        def helper(i, sum):
            if sum == target:
                combs.append(curComb.copy())
                return
            if i>=len(nums) or sum>target:
                return
            
            sum+=nums[i]
            curComb.append(nums[i])
            helper(i,sum)

            sum-=nums[i]
            curComb.pop()
            helper(i+1,sum)
        
        helper(0,0)
        return combs
