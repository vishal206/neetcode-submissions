class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>nums[l]){
                // left sorted portion
                if(target>nums[mid] || target < nums[l]){
                    l = mid+1;
                }else {
                    // target < nums[mid] && target > nums[l]
                    r = mid -1;
                }
            }
            else{
                //right sorted portion
                if (target < nums[mid] || target > nums[r]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};
