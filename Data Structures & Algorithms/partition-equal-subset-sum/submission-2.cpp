class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tSum=0;
        for(int i=0;i<nums.size();i++){
            tSum += nums[i];
        }

        if(tSum%2 != 0){
            return false;
        }

         
        int capacity = tSum/2;

        int N = nums.size(), M = capacity;
        vector<vector<int>> cache(N, vector<int>(M + 1, -1));


        return knapsack(nums, 0, capacity, cache);
    }

private:
    bool knapsack(vector<int>& nums, int i, int capacity, vector<vector<int>>& cache){
        if(capacity<0 || i == nums.size()){
            return false;
        }
        if(capacity == 0){
            return true;
        }

        if(cache[i][capacity]==0){
            return false;
        }

        if(cache[i][capacity]==1){
            return true;
        }

        //skip
        bool skip = knapsack(nums, i+1, capacity, cache);
        cache[i][capacity] = skip;
        // not skip
        bool notSkip = knapsack(nums, i+1, capacity-nums[i], cache);
        cache[i][capacity] = skip || notSkip;

        return cache[i][capacity];
    }
};
