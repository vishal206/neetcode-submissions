class Solution {
public:
    int countSubstrings(string s) {
        // int resLen = 0, resIdx =0;
        int res = 0;

        for(int i=0; i< s.size();i++){
            // odd length palindrom "aba"

            int l = i, r = i; // a single letter is also a palindrom ( on itself )

            while(l>=0 && r< s.size() && s[l] == s[r]) //taking the i as the center
            {
                res++;
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
                res++;
                //check goes on
                l--;
                r++; 
            }
        }

        return res;
    }
};
