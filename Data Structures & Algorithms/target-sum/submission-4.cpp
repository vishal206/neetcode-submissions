class Solution {
// Memoization but without using an 2d array
public:
    int count = 0;
    map<pair<int,int>,int> cache;
    int findTargetSumWays(vector<int>& nums, int target) {
        
        dfs(0, nums, target);
        return count;
    }

    void dfs(int i, vector<int>& nums, int target){
        if(cache.count({i,target})){
            return;
        }
        if(i==nums.size()){
            if(target==0) count++;
            return;
        }
        
        dfs(i+1, nums, target+nums[i]);
        dfs(i+1, nums, target-nums[i]);

        cache[{i,target}] = count;
        
    }
};
