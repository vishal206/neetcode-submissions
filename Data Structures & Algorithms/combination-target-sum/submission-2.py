class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []

        cur = []
        sum=0
        def dfs(i):
            nonlocal sum
            if sum == target:
                res.append(cur.copy())
                return
            
            if i >=len(nums) or sum > target:
                return
            
            sum+=nums[i]
            cur.append(nums[i])
            dfs(i)

            cur.pop()
            sum-=nums[i]
            dfs(i+1)
        dfs(0)
        return res