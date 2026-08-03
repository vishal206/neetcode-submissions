class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        targetMinusNum = {}

        for i,num in enumerate(nums):
            if target-num not in targetMinusNum:
                targetMinusNum[num] = i
            else:
                return [targetMinusNum[target-num],i]