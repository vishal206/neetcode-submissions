class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        adj = {}
        for i in range(numCourses):
            adj[i]=[]
        
        for src, dst in prerequisites:
            adj[src].append(dst)
        
        topSort = []
        visited = set()
        path = []

        def dfs(src)->bool:
            if src in path:
                return False
            if src in visited:
                return True
            
            visited.add(src)
            path.append(src)

            for nei in adj[src]:
                if not dfs(nei):
                    return False
            topSort.append(src)
            path.pop()

            return True

        for i in range(numCourses):
            if not dfs(i):
                return []
        
        return topSort