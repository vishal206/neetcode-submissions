class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        countSMap = {}
        countTMap = {}

        for char in s:
            if char not in countSMap:
                countSMap[char] = 1
            else:
                countSMap[char]+=1
        
        for char in t:
            if char not in countTMap:
                countTMap[char] = 1
            else:
                countTMap[char]+=1
        
        return countSMap == countTMap