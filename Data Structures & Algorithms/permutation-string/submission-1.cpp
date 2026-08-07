class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }

        vector<int> s1Count(26,0);
        vector<int> s2Count(26,0);

        for(int i=0;i<s1.length();i++){
            s1Count[s1[i]-'a']++;
            s2Count[s2[i]-'a']++;
        }
        if(s1Count == s2Count){
            return true;
        }
        int l=0, r=s1.length()-1;
        while(r < s2.length() - 1){
            s2Count[s2[l]-'a']--;
            l++;
            r++;
            s2Count[s2[r]-'a']++;
            if(s1Count == s2Count){
                return true;
            }
        }

        return false;
    }
};