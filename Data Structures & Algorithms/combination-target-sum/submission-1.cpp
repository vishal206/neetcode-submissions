class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums,result,subset,0, target);

        return result;
    }
private:
    void backtrack(vector<int> nums,vector<vector<int>>& result,vector<int> subset, int index, int target){
        if(target==0){
            result.push_back(subset);
            return;
        }
        if(target<0 || index==nums.size()){
            return;
        }

        backtrack(nums,result,subset,index+1,target); // Not picking nums[index]

        subset.push_back(nums[index]); //  picking nums[index]
        backtrack(nums,result,subset,index,target-nums[index]);

        return;
    }
};
