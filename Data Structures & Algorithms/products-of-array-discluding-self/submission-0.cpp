class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        vector<int> pre,suf;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==0 || i==1){
                pre.push_back(nums[0]);
            }else{
                pre.push_back(nums[i-1]*pre[i-1]);
            }
        }
        //  for(auto x:pre){
        //  	cout<<x<<" ";
        //  }
        //  cout<<endl;
        for(int i=n-1;i>=0;i--){
            if(i==n-1 || i==n-2){
                suf.push_back(nums[n-1]);
            }else{
                suf.push_back(nums[i+1]*suf.back());
            }
        }
        //  for(auto x:suf){
        //  	cout<<x<<" ";
        //  }
        //  cout<<endl;
        for(int i=0;i<n;i++){
            if(i==0){
                result.push_back(suf[n-1]);
            }else if(i==n-1){
                result.push_back(pre[n-1]);
            }else{
                result.push_back(pre[i]*suf[n-1-i]);
            }
        }

        return result;
    }
};
