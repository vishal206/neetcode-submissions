class Solution {
public:
    set<pair<int, int>> path;
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++){
            for(int j =0; j < board[0].size();j++){
                    if(backtrack(board,word,i,j,0)){
                        return true;
                    }
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int i, int j,int wi){
        if(wi==word.size()){
            return true;
        }

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
        
        if( board[i][j] != word[wi] || path.count({i,j})) return false; //visiting the same element
        
        // if character match
        path.insert({i,j});
        
        bool res = backtrack(board, word, i+1, j, wi+1) || 
        backtrack(board, word, i, j+1, wi+1) || 
        backtrack(board, word, i-1, j, wi+1) || 
        backtrack(board, word, i, j-1, wi+1);
        
        path.erase({i,j});

        return res;


    }
};
