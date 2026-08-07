class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m,vector<int>(n,-1));

        return dfs (0,0,cache,m,n);
    }

    int dfs(int row, int col,vector<vector<int>>& cache, int m, int n ){
        if(row==m-1 && col==n-1){
            return 1;
        }
        if(col>n-1 || row>m-1){
            return 0;
        }
        if(cache[row][col]!=-1) return cache[row][col];

        cache[row][col] = dfs(row+1,col,cache,m,n) + dfs(row,col+1,cache,m,n);

        return cache[row][col];
    }
};