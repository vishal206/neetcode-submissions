class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> subsets;
        vector<int> subset;
        backtrack(nums,subsets, 0, subset);

        return vector<vector<int>> (subsets.begin(), subsets.end());
    }

    void backtrack(vector<int> nums, set<vector<int>>& subsets, int pos, vector<int>& subset){
        if(pos==nums.size()){
            subsets.insert(subset);
            return;
        }

        
        backtrack(nums,subsets, pos+1, subset);

        subset.push_back(nums[pos]);
        backtrack(nums, subsets, pos+1, subset);

        subset.pop_back();
        return;
    }
};