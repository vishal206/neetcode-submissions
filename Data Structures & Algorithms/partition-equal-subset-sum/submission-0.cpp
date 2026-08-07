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
        return knapsack(nums, 0, capacity);
    }

private:
    bool knapsack(vector<int>& nums, int i, int capacity){
        if(capacity<0 || i == nums.size()){
            return false;
        }
        if(capacity == 0){
            return true;
        }

        //skip
        bool skip = knapsack(nums, i+1, capacity);

        // not skip
        bool notSkip = knapsack(nums, i+1, capacity-nums[i]);

        return skip || notSkip;
    }
};
