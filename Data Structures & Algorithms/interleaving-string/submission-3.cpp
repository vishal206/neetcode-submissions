class Solution {
    vector<vector<int>> cache;
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size(), size2 = s2.size(); 
        if(size1+size2 != s3.size()){
            return false;
        }

        cache = vector<vector<int>>(size1 + 1, vector<int>(size2 + 1, -1));

        return dfs(s1, s2, s3, 0, 0, 0);
    }

    bool dfs(string s1, string s2, string s3 , int i1 ,int i2, int i3){
        if(i3==s3.size()){
            return (i1 == s1.length()) && (i2 == s2.length());
        }

        if(cache[i1][i2] != -1){
            return cache[i1][i2];
        }

        bool res = false;
        if(s1[i1]==s3[i3] && s2[i2]==s3[i3]){
            res = dfs(s1, s2, s3, i1+1, i2, i3+1) || dfs(s1, s2, s3, i1, i2+1, i3+1);
        }

        else if(s1[i1]==s3[i3]){
            res= dfs(s1, s2, s3, i1+1, i2, i3+1);
        }
        else if(s2[i2]==s3[i3]){
            res= dfs(s1, s2, s3, i1, i2+1, i3+1);
        }

        cache[i1][i2] = res;
        return res;

    }
};
