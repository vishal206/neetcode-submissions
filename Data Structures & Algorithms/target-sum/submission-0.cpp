class Solution {
public:
    int len, target_cp;
    int findTargetSumWays(vector<int>& nums, int target) {
        len = nums.size();
        target_cp = target;
        unordered_map<int, int> dp;

        return backtrack(0, 0, nums, dp);
    }

    int backtrack(int i, int cur_sum, vector<int>& nums, unordered_map<int, int>& dp){
        // if()

        if(i==len){
            return cur_sum == target_cp ? 1 : 0;
        }

        return( backtrack(i+1, cur_sum + nums[i], nums, dp) + backtrack(i+1, cur_sum + nums[i], nums, dp) );
    }
};
