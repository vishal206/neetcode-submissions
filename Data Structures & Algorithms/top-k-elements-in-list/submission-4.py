class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        numCount = {}
        for num in nums:
            numCount[num] = numCount.get(num,0)+1
        
        sorted_keys = sorted(numCount, key=numCount.get, reverse=True)

        return sorted_keys[:k]