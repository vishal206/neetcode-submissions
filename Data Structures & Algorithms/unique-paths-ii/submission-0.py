class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        rows, cols = len(obstacleGrid), len(obstacleGrid[0])
        dp = [0]*cols
        dp[cols-1]=1

        for r in reversed(range(rows)):
            for c in reversed(range(cols)):
                if obstacleGrid[r][c]:
                    dp[c] = 0 #obstacle
                elif c < cols-1:
                    dp[c] = dp[c] + dp[c+1]
                # else:
                #     dp[c] = dp[c] no need for this, as this is by default
        return dp[0]