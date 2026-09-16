class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        subsets = []
        curSet = []

        def helper(i, curSet, subsets):
            if i == len(nums):
                subsets.append(curSet.copy())
                return
            
            #include
            curSet.append(nums[i])
            helper(i+1, curSet, subsets)

            curSet.pop()
            helper(i+1, curSet, subsets)
        
        helper(0, curSet, subsets)

        return subsets