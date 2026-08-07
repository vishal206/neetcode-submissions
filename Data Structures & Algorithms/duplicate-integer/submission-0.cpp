class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size()==0)
        return false;
        set<int> arrSet;
        for(int i=0;i<nums.size();i++){
            if(arrSet.insert(nums[i]).second){
                arrSet.insert(nums[i]);
            }else{
                return true;
            }
        }
        return false;
    }
};
