class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums,result,subset,0);
        return result;

    }

private:
    void backtrack(vector<int>& nums,vector<vector<int>>& result,  vector<int> subset, int index){
        if(index==nums.size()){
            result.push_back(subset);
            return;
        }

        backtrack(nums,result,subset,index+1); // Not picking nums[i]
        
        subset.push_back(nums[index]); // picking nums[i]
        backtrack(nums,result,subset,index+1);

        return;
    }
};
