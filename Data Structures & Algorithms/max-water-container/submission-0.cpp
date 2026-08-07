class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int maxWater=0;
        while(l<r){
            int water = (r-l)*min(height[l],height[r]);
            maxWater=max(maxWater,water);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }

        return maxWater;
    }
};