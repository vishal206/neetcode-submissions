class Solution {
public:
    int ROWS,COLS;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        //position that can reach each ocean
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        
        for(int c = 0; c < COLS; c++){
            dfs(0, c, pac, heights);// going through first row
            dfs(ROWS-1, c, atl, heights); //going through last row
        }

        for(int r = 0; r < ROWS; r++){
            dfs(r, 0, pac, heights); // going through first col
            dfs(r, COLS-1, atl, heights); // going through last COL
        }

        vector<vector<int>> res;

        for(int r =0; r < ROWS ; r++){
            for(int c = 0; c < COLS ; c++){
                if(pac[r][c] && atl[r][c]){
                    res.push_back({r, c});
                }
            }
        }

        return res;

    }

    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        ocean[r][c] = true;
        for(auto [dr, dc] : dirs){
            int nr = r + dr, nc = c + dc;
            if(
                nr >= 0 && nr < ROWS && nc >=0 && nc < COLS &&
                !ocean[nr][nc] && heights[nr][nc] >= heights[r][c] //as we are coming from ocean, we go backwards
            ){
                dfs(nr, nc, ocean, heights);
            }
        }
    }
};
