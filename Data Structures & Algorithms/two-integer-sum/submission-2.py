class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {} #num:index

        for index, value in enumerate(nums):
            if target-value in hashmap:
                return [hashmap[target-value], index]
            hashmap[value]=index
        
        return [-1,-1]