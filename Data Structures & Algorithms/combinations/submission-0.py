class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        curComb = []
        comb = []

        def helper(i):
            if len(curComb) == k:
                comb.append(curComb.copy())
                return
            if i>n:
                return
            
            
            curComb.append(i)
            helper(i+1)
            curComb.pop()

            helper(i+1)
        
        helper(1)
        return comb
