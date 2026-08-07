class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string stack;
        backtrack(0,0,n,result,stack);
        return result;
    }

    void backtrack(int openCount, int closeCount, int n, vector<string>& result, string& stack){
        if(openCount == closeCount && closeCount == n){
            result.push_back(stack);
        }

        if(openCount < n){
            stack += '(';
            backtrack(openCount+1,closeCount,n,result, stack);
            stack.pop_back();
        }

        if(closeCount < openCount){
            stack += ')';
            backtrack(openCount, closeCount + 1, n, result, stack);
            stack.pop_back();
        }
    }
};
