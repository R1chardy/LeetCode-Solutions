class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret = {};
        vector<int> ans = {};
        dfs(n, k, ans, ret);
        return ret;
    }
    
    void dfs(int n, int k, vector<int>& ans, vector<vector<int>>& ret, int len = 0, int num = 1){
        if(len >= k){
            ret.push_back(ans);
            return;
        }
        else{
            for(int i = num; i <= n; i++){
                ans.push_back(i);
                dfs(n,k,ans,ret,len+1,i+1);
                ans.pop_back();
            }
        }
    }
};