class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> cache(text1.size(),vector<int>(text2.size(),-1));

        return dfs(0,0,cache,text1,text2);

    }

    int dfs(int index1, int index2, vector<vector<int>>& cache, string text1, string text2){
        if(index1>=text1.size() || index2>=text2.size()){
            return 0;
        }

        if(cache[index1][index2]!=-1) return cache[index1][index2];

        if(text1[index1]==text2[index2]){
            cache[index1][index2] = 1+ dfs(index1+1,index2+1,cache,text1,text2);
        }else{
            cache[index1][index2] = max(dfs(index1,index2+1,cache,text1,text2),dfs(index1+1,index2,cache,text1,text2));
        }

        return cache[index1][index2];
    }
};