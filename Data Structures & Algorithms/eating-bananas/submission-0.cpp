class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r= *max_element(piles.begin(),piles.end()); //does not return an int. Instead, it returns an iterator, so we use *
        int res = r;

        while(l<=r){
            int k = (l+r)/2;
            int totalTime = 0;
            // long long totalTime = 0; // safer to use long long for big numbers
            for(int p:piles){
                totalTime += ceil((double)p/k); // if both p and k are integer , int division happen thats why we add (double)
                // Example 9/2 will give 4 not 4.5
            }
            if(totalTime<=h){
                res=k;
                r=k-1;
            }else{
                l=k+1;
            }
        }
        return res;
    }
};
