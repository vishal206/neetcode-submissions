class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        countS = {}
        countT = {}

        for index in range(len(s)):
            if s[index] in countS:
                countS[s[index]]+=1
            else:
                countS[s[index]]=1
            
            if t[index] in countT:
                countT[t[index]]+=1
            else:
                countT[t[index]]=1
        
        return countS==countT