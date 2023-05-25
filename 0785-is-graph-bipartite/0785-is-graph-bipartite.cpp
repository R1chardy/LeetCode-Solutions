class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> dp(graph.size(), 0);
        for(int i = 0; i < graph.size(); i++){
            if(!solve(graph, i, dp)){
                return false;
            }
        }
        return true;;
    }
    
    bool solve(vector<vector<int>>& graph, int n, vector<int>& dp){
        if(dp[n] != 0){
            return true;
        }
        queue<int> q;
        q.push(n);
        dp[n] = -1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto& nei : graph[top]){
                if(dp[nei] != 0 && dp[nei] == dp[top]){
                    return false;
                }
                else if(dp[nei] == 0){
                    dp[nei] = -1 * dp[top];
                    q.push(nei);
                }
            }
        }
        return true;
    }
};