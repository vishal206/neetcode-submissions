class Solution {
public:
    int result = 0;
    int change(int amount, vector<int>& coins) {
        dfs(amount, coins, 0);
        return result;
    }
    void dfs(int amount, vector<int>& coins, int pointer){
        if(amount<0){
            return;
        }
        if(amount == 0){
            result++;
            return;
        }

        for(int i = pointer; i<coins.size();i++){
            dfs(amount - coins[i], coins, pointer);
            pointer++;
        }
    }
};
