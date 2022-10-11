class Solution {
public:
    vector<string> ret = {};
    vector<string> generateParenthesis(int n) {
        dfs(n);
        return ret;
    }
    
    void dfs(int n, int open = 0, int close = 0, string str = ""){
        if(open == close && open == n){
            ret.push_back(str);
            return;
        }
        else if(open > close && open == n){
            dfs(n, open, close+1, str + ')');
        }
        else if(open >= close && open < n){
            dfs(n, open+1, close, str + '(');
            dfs(n, open, close+1, str + ')');
        }
        else{
            return;
        }
    }
};