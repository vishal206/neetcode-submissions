class Solution {
public:
    int ROWS,COLS;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        for(int r = 0; r<ROWS; r++){
            if(board[r][0]=='O'){
                dfs(r,0,board); //first column
            }
            if(board[r][COLS-1]=='O'){
                dfs(r, COLS-1,board); //last col
            }
        }

        for(int c = 0;c<COLS;c++){
            if(board[0][c]=='O'){
                dfs(0,c,board); // first row
            }
            if(board[ROWS-1][c]=='O'){
                dfs(ROWS-1,c,board); //last row
            }
        }

        for(int r=0; r<ROWS; r++){
            for(int c=0; c<COLS; c++){
                if(board[r][c]=='O'){
                    board[r][c]= 'X';
                }else if(board[r][c]=='#'){
                    board[r][c]= 'O';
                }
                
            }
        }
    }

    void dfs(int r, int c, vector<vector<char>>& board){
        // cout<<r<<"-"<<c<<"#"<<endl;
        board[r][c] = '#';
        for(auto [dr,dc]:dirs){
            int nr=r+dr;
            int nc=c+dc;

            if(nr<0 || nc<0 || nr>ROWS-1 || nc>COLS-1
            || board[nr][nc]=='#' || board[nr][nc]=='X'){
                continue;
            }

            dfs(nr, nc, board);
        }
    }
};