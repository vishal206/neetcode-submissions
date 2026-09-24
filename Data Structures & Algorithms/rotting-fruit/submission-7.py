class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        bananaCount = 0
        queue = deque()
        visited = set()
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1 or grid[r][c] == 2:
                    bananaCount+=1
                if grid[r][c] == 2:
                    queue.append((r,c))
                    visited.add((r,c))
        
        if len(queue) == 0 and bananaCount > 0:
            return -1
        if len(queue) == 0:
            return 0
        
        length = 1

        while queue:
            for i in range(len(queue)):
                r, c = queue.popleft()
                neighbors = [[0,1],[0,-1],[1,0],[-1,0]]
                for dr, dc in neighbors:
                    ir = r+dr
                    ic = c+dc
                    if(ir < 0 or ic < 0 or ir >= ROWS or ic >= COLS or ( ir, ic) in visited or grid[ir][ic] == 0 or grid[ir][ic] == 2):
                        continue
                    queue.append((ir,ic))
                    visited.add((ir,ic))
                if bananaCount == len(visited):
                    return length
            length += 1
        return -1