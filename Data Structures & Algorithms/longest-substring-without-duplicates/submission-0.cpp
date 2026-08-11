class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1){
            return 1;
        }
        int l=0,r=1;
        set<char> uniqueCharacters;
        uniqueCharacters.insert(s[l]);

        int length =1;

        while(r<s.length()){
            if(uniqueCharacters.count(s[r])){
                uniqueCharacters.erase(s[l]);
                l++;
            }else{
                uniqueCharacters.insert(s[r]);
                length=max(length,r-l+1);
                r++;
            }

            
        }

        return length;
    }
};
