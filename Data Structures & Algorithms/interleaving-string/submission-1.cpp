class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return dfs(s1, s2, s3, 0, 0, 0);
    }

    bool dfs(string s1, string s2, string s3 , int i1 ,int i2, int i3){
        if(i3==s3.size()){
            return true;
        }

        if(s1[i1]==s3[i3] && s2[i2]==s3[i3]){
            return dfs(s1, s2, s3, i1+1, i2, i3+1) || dfs(s1, s2, s3, i1, i2+1, i3+1);
        }

        else if(s1[i1]==s3[i3]){
            return dfs(s1, s2, s3, i1+1, i2, i3+1);
        }
        else if(s2[i2]==s3[i3]){
            return dfs(s1, s2, s3, i1, i2+1, i3+1);
        }

        return false;

    }
};
