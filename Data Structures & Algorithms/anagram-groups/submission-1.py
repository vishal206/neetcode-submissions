class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashMap = {} #sorted_string: arrayOfStrings
        for str in strs:
            sorted_str = "".join(sorted(str))
            if sorted_str in hashMap:
                hashMap[sorted_str].append(str)
            else:
                hashMap[sorted_str]=[]
                hashMap[sorted_str].append(str)
        result = []
        for key, value in hashMap.items():
            result.append(value)
        
        return result