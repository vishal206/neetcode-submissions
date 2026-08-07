class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>, int> dp; // (index, cur_sum) - > number of ways

        return backtrack(0, 0, nums, dp, target);
    }

    int backtrack(int i, int cur_sum, vector<int>& nums, map<pair<int,int>, int>& dp, int target){
        if(dp.count({i,cur_sum})){
            return dp[{i, cur_sum}];
        }

        if(i==nums.size()){
            return cur_sum == target ? 1 : 0;
        }

        dp[{i, cur_sum}] = ( backtrack(i+1, cur_sum + nums[i], nums, dp, target) + backtrack(i+1, cur_sum - nums[i], nums, dp, target) );

        return dp[{i, cur_sum}];
    }
};
