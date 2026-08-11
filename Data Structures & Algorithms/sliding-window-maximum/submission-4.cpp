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
                max = INT_MIN;
                for(int i=0;i<k;i++){
                    if(nums[l+i]>max){
                        max=nums[l+i];
                        // cout<<l<<"+"<<i<<"-"<<max<<endl;
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
