class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size()+1,-1);
        return dfs(0, nums, cache);
    }

    int dfs(int i, vector<int>& nums, vector<int>& cache){
        if(i>=nums.size()){
            return 0;
        }
        if(cache[i]!=-1){
            return cache[i];
        }
        cache[i] = max(nums[i]+dfs(i+2, nums, cache),dfs(i+1, nums, cache));

        return cache[i];
    }
};
