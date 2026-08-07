class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n+1,-1);

        return dfs(n,cache);
    }

    int dfs( int n, vector<int>& cache){
        if(n<0){
            return 0;
        } 
        if(n==0){
            return 1;
        }
        if(cache[n]!=-1) return cache[n];

        cache[n]=dfs(n-1,cache)+dfs(n-2,cache);

        return cache[n];
    }
};
