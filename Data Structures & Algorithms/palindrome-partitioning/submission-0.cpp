class Solution {
public:
    vector<vector<string>> res;
    vector<string> part;
    vector<vector<string>> partition(string s) {
        dfs(0,s);
        return res;
    }

private:
    void dfs(int i, const string& s){
        if(i>=s.length()){
            res.push_back(part); // you have finsihed the string on one partition ( eg: a)
        }

        for(int j = i; j< s.length(); j++){
            if(isPali(s, i, j)){ // substring 0->j at start
                part.push_back(s.substr(i,j-i+1)); // adding palendrom substrings
                dfs(j+1, s);
                part.pop_back();
            }
        }
    }

    bool isPali(const string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
