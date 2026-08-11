class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString;
        char delimiter='#';
        
        for(auto str:strs){
            encodedString+=str+delimiter;
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        string tempStr;
        vector<string> decodedStrs;
        char delimiter='#';
        
        for(int i=0;i<s.length();i++){
            if(s[i]==delimiter){
                decodedStrs.push_back(tempStr);
                tempStr.clear();
            }else{
                tempStr+=s[i];
            }
        }
        
        return decodedStrs;
    }
};
