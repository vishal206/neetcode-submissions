class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        int maxSum=0;
        for(int row=0;row<ROW;row++){
            for(int col=0;col<COL;col++){
                int sum=0;
                dfs(grid,row,col,sum);
                if(sum>maxSum){
                    maxSum=sum;
                }
            }
        }

        return maxSum;
    }
    void dfs(vector<vector<int>>& grid, int row, int col, int& sum){
        if(col<0 || row<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==0){
            return;
        }

        sum++;
        grid[row][col]=0;

        dfs(grid,row+1,col,sum);
        dfs(grid,row,col+1,sum);
        dfs(grid,row,col-1,sum);
        dfs(grid,row-1,col,sum);

        return;
    }
};
