class Solution {
public:
    string longestPalindrome(string s) {
        int resLen = 0, resIdx =0;

        for(int i=0; i< s.size();i++){
            // odd length palindrom "aba"

            int l = i, r = i; // a single letter is also a palindrom ( on itself )

            while(l>=0 && r< s.size() && s[l] == s[r]) //taking the i as the center
            {
                if( r - l + 1 > resLen){
                    resIdx = l; //update the result
                    resLen = r - l +1;
                }
                //check goes on
                l--;
                r++; 
            }

            //even length pal "acca"
            l = i;
            r = i + 1; // checking the next element
            //same palindrom check as before
            while(l>=0 && r< s.size() && s[l] == s[r]) //taking the i as the center
            {
                if( r - l + 1 > resLen){
                    resIdx = l; //update the result
                    resLen = r - l +1;
                }
                //check goes on
                l--;
                r++; 
            }
        }

        return s.substr(resIdx, resLen);
    }
};
