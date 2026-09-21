class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = {}
        for i in range(1,n+1):
            adj[i]=[]
        
        for u,v,t in times:
            adj[u].append([v,t])
        
        time = 0
        shortest = {}
        minHeap = [[0, k]]

        while minHeap:
            t1, v1 = heapq.heappop(minHeap)
            if v1 in shortest:
                continue
            shortest[v1] = t1
            time=t1

            for v2, t2 in adj[v1]:
                heapq.heappush(minHeap, [t1+t2,v2])

        if len(shortest)!=n:
            return -1
        
        return time 

