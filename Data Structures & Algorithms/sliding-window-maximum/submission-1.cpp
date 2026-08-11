class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        int l=0, r=0;
        vector<int> res;
        int max = INT_MIN;
        for(r=0;r<k;r++){
            if(nums[r]>max){
                max=nums[r];
            }
        }
        res.push_back(max);

        while(r<nums.size()){
            // r++;
            // l++;
            if(max>nums[r] && max == nums[l]){
                l++;
                for(int i=0;i<k;i++){
                    if(nums[l+1]>max){
                        max=nums[i];
                    }
                }
            }
            else if(nums[r]>max){
                max = nums[r];
                l++;
            }

            res.push_back(max);
            r++;
        }

        return res;
    }
};
