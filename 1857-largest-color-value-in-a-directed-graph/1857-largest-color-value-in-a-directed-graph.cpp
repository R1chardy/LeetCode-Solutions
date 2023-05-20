class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        for(auto& edge : edges){
            mp[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> visited(colors.length());
        vector<bool> curStack(colors.length());
        vector<vector<int>> dp(colors.length(), vector<int>(26));
        
        for(int i = 0; i < colors.length(); i++){
            if(solve(colors, mp, visited, curStack, dp, i)){
                return -1;
            }
        }
        
        int ret = 0;
        for(auto& x : dp){
            for(auto& y : x){
                ret = max(ret, y);
            }
        }
        
        return ret;
    }
    
    bool solve(const string& colors, unordered_map<int,vector<int>>& mp, vector<bool>& visited, vector<bool>& curStack, vector<vector<int>>& dp, int i){
        if(curStack[i] && visited[i]){
            return true;
        }
        
        if(visited[i]){
            return false;
        }
        
        visited[i] = true;
        curStack[i] = true;
        
        for(auto& x : mp[i]){
            if(solve(colors, mp, visited, curStack, dp, x)){
                return true;
            }
            
            for(int y = 0; y < 26; y++){
                dp[i][y] = max(dp[i][y], dp[x][y]);
            }
        }
        
        dp[i][colors[i]-'a']++;
        curStack[i] = false;
        return false;
    }
};