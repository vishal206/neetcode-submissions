class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        adj = {}
        for i in range(numCourses):
            adj[i]=[]
        for pre, crs in prerequisites:
            adj[crs].append(pre)
        
        preMap = {}
        
        def dfs(crs):
            if crs not in preMap:
                preMap[crs] = set()

                for pre in adj[crs]:
                    preMap[crs] |= dfs(pre) #union
                preMap[crs].add(crs)
            return preMap[crs]


        for crs in range(numCourses):
            dfs(crs)
        
        result = []
        for u, v in queries:
            if u in preMap[v]:
                result.append(True)
            else:
                result.append(False)

        return result;