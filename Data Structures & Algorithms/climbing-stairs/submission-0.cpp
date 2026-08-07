class Solution {
public:
    int climbStairs(int n) {
        int result=0;
        dfs(result,n);

        return result;
    }

    void dfs(int& result, int n){
        if(n<0){
            return;
        }
        if(n==0){
            result++;
        }

        dfs(result,n-1);
        dfs(result,n-2);
    }
};
