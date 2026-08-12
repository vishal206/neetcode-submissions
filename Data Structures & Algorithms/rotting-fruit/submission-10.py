class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        fresh = 0
        queue = deque()

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    fresh+=1
                if grid[r][c] == 2:
                    queue.append((r,c))
        
        length = 0
        while fresh>0 and queue:
            size = len(queue)
            for i in range(size):
                r, c = queue.popleft()
                
                neighbors = [[0,1],[0,-1],[1,0],[-1,0]]
                for dr, dc in neighbors:
                    row = r+dr
                    col = c+dc
                    if(row in range(len(grid)) and col in range(len(grid[0])) and grid[row][col] == 1):
                        queue.append((row,col))
                        grid[row][col] = 2
                        fresh -=1
            length += 1
        return length if fresh == 0 else -1