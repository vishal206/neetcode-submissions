class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> isPicked(nums.size(), false);
        vector<int> perm;
        backtrack(perm, nums, isPicked);
        return result;
    }

    void backtrack(vector<int>& perm,vector<int>& nums,vector<bool>& isPicked){
        if(perm.size()==nums.size()){
            result.push_back(perm);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!isPicked[i]){
                perm.push_back(nums[i]);
                isPicked[i]=true;
                backtrack(perm, nums, isPicked);
                perm.pop_back();
                isPicked[i]=false;
            }
        }
    }
};
