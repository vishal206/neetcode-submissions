class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int i1 = 0, i2 =0;

        for(int i=0;i<s3.size();i++){
            if(s1[i1]==s3[i]){
                i1++;
                continue;
            }
            if(s2[i2]==s3[i]){
                i2++;
                continue;
            }

            return false;
        }

        return true;
    }
};
