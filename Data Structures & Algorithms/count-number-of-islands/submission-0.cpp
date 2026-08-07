class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int noRow=grid.size();
        int noCol=grid[0].size();
        int noIsland = 0;
        for(int row=0;row<noRow;row++){
            for(int col=0;col<noCol;col++){
                if(grid[row][col]=='1'){
                    dfs(grid,row,col);
                    noIsland++;
                }
            }
        }

        return noIsland;
    }
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row >= grid.size() || col >= grid[0].size() || row<0 || col<0 || grid[row][col]=='0'){
            return;
        }
        grid[row][col]='0';
        dfs(grid,row+1,col);
        dfs(grid,row,col+1);
        dfs(grid,row-1,col);
        dfs(grid,row,col-1);

        return;
    }

};
