class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString;
        char delimiter='#';
        
        for(auto str:strs){
            encodedString+=to_string(str.length())+delimiter+str;
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        string tempStr;
        vector<string> decodedStrs;
        char delimiter='#';
        int len;

        for(int i=0;i<s.length();i++){
            if(s[i]==delimiter){
                len=stoi(tempStr);
                decodedStrs.push_back(s.substr(i+1,len));
                i=i+len;
                tempStr.clear();
            }else{
                tempStr+=s[i];
            }
        }
        
        return decodedStrs;
    }
};
