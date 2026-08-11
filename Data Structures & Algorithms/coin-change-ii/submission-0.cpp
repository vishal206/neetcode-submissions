class Solution {
public:
    int result = 0;
    int change(int amount, vector<int>& coins) {
        dfs(amount, coins);
        return result;
    }
    void dfs(int amount, vector<int>& coins){
        if(amount<0){
            return;
        }
        if(amount == 0){
            result++;
            return;
        }

        for(int n : coins){
            dfs(amount - n, coins);
        }
    }
};
