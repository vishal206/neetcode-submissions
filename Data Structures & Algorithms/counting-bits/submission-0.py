class Solution:
    def countBits(self, n: int) -> List[int]:
        res = [0]*(n+1)
        for i in range(n+1):
            count = 0
            j=i
            while i>0:
                if i&1 == 1:
                    count += 1
                i=i>>1
            res[j]=count
        return res