class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size(),-1);

        return min(dfs(cost,cache,0),dfs(cost,cache,1));
    }

    int dfs(vector<int>& cost, vector<int>& cache,int index){
        if(index>=cost.size()){
            return 0;
        }
        if(cache[index]!=-1) return cache[index];

        cache[index] = cost[index]+ min( dfs(cost,cache,index+1), dfs(cost,cache,index+2));

        return cache[index];
    }
};
