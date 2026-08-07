class Solution {
// Memoization but without using an 2d array
public:
    int count = 0;
    map<pair<int,int>,int> cache;
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return dfs(0, nums, target);
    }

    int dfs(int i, vector<int>& nums, int target){
        if(cache.count({i,target})){
            return cache[{i,target}];
        }
        if(i==nums.size()){
            if(target==0) return 1;
            return 0;
        }
        
        cache[{i,target}] = dfs(i+1, nums, target+nums[i]) + dfs(i+1, nums, target-nums[i]);

        return cache[{i,target}];
        
    }
};
