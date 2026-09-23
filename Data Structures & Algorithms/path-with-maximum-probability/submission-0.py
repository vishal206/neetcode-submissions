class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        adj = {}
        for i in range(n):
            adj[i] = []
        
        for i in range(len(edges)):
            src, dst = edges[i]
            adj[src].append((dst, succProb[i]))
            adj[dst].append((src, succProb[i]))
        
        maxHeap = [(-1, start_node)] #assuming prob is 1, minus because it's a maxHeap
        visit = set()

        while maxHeap:
            prob, cur = heapq.heappop(maxHeap)
            visit.add(cur)

            if cur == end_node:
                return prob * -1 # maxHeap
            
            for nei, edgeProb in adj[cur]:
                if nei not in visit:
                    heapq.heappush(maxHeap,(prob * edgeProb, nei))
        return 0