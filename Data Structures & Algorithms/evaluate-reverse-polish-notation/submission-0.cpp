#include <string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                numStack.push(stoi(tokens[i]));
            }else if(numStack.size()>0){
                int b=numStack.top();
                numStack.pop();
                int a=numStack.top();
                numStack.pop();
                int result;
                if( tokens[i]=="+"){
                    result = a+b;
                }else if( tokens[i]=="-"){
                    result = a-b;
                }else if( tokens[i]=="*"){
                    result = a*b;
                }else if( tokens[i]=="/"){
                    result = a/b;
                }

                numStack.push(result);
            }
        }

        return numStack.top();
    }
};
