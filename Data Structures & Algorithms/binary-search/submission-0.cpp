class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        while(start<=end){
            int middle = (start+end)/2;

            if(nums[middle]==target){
                return middle;
            }

            if(target>nums[middle]){
                start=middle+1;
            }else{
                end=middle-1;
            }
        }

        return -1;
    }
};
