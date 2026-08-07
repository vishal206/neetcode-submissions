class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        unordered_map<char,int> countT, window;

        for(char c: t){
            countT[c]++;
        }

        int have = 0; // to check if the character count is met
        int need = countT.size(); //unique character in t

        pair<int,int> res = {-1,-1};
        int resLen = INT_MAX;
        int l = 0; //left pointer

        for(int r=0; r<s.size(); r++){
            char c = s[r];
            window[c]++;

            if(countT[c] && window[c] == countT[c])// check if the char is in countT and if the count matches.
            {
                have++; //just satisfied a single char condition
            }

            while(have == need){
                if(r-l+1 < resLen) //if current window length is less than result len
                {
                    res = {l,r};
                    resLen = r-l+1;
                }
                //pop from left
                window[s[l]]--;
                if(countT[s[l]] && window[s[l]] < countT[s[l]]){
                    have--; //condition for single char not met
                }
                l++; 

            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
