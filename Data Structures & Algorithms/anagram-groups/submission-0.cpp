class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> anagramGroupMap;
        vector<vector<string>> result;
        // countMap, index
        for(int i=0;i<strs.size();i++){
            map<char,int> countMap;
            for(int j=0;j<strs[i].length();j++){
                countMap[strs[i][j]]++;
            }
            anagramGroupMap[countMap].push_back(strs[i]);
        }
        
        for(auto entry : anagramGroupMap){
            result.push_back(entry.second);
        } 
        return result;
    }
};
