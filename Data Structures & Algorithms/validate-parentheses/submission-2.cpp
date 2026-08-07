#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> pStack;

        for(int i;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                pStack.push(s[i]);
            }else if(pStack.size()>0){
                if(s[i]==')' && pStack.top()=='(' ||
                s[i]=='}' && pStack.top()=='{' ||
                s[i]==']' && pStack.top()=='['){
                    pStack.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        
        if(pStack.size()==0) return true;
        
        return false;
    }
};
