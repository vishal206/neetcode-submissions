#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.length()-1;
        bool result = true;
         std::transform(s.begin(), s.end(), s.begin(),
                   ::tolower);
        while(l<r){
            if(!isalnum(s[l])){
                l++;
                continue;
            }
            if(!isalnum(s[r])){
                r--;
                continue;
            }
            std::cout<<s[l]<<" "<<s[r]<<endl;
            if(s[l]==s[r]){
                l++;
                r--;
                continue;
            }
            if(s[l]!=s[r]){
                result = false;
                break;
            }
        }

        return result;
    }
};
