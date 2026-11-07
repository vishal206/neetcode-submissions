class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        singleValue = set()

        for num in nums:
            singleValue.add(num)
        
        if len(singleValue)!=len(nums):
            return True
        return False