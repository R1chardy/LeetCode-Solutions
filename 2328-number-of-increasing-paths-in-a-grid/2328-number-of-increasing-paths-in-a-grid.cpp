class Solution {
public:
    int mod = 1e9+7;
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        int num = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                num += solve(grid, dp, i, j)%mod;
                num %= mod;
            }
        }
        return num;
    }
    
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int num = 1;
        if(valid(grid, i+1, j) && grid[i+1][j] > grid[i][j]){
            num += solve(grid, dp, i+1, j)%mod;
            num %= mod;
        }
        if(valid(grid, i-1, j) && grid[i-1][j] > grid[i][j]){
            num += solve(grid, dp, i-1, j)%mod;
            num %= mod;
        }
        if(valid(grid, i, j+1) && grid[i][j+1] > grid[i][j]){
            num += solve(grid, dp, i, j+1)%mod;
            num %= mod;
        }
        if(valid(grid, i, j-1) && grid[i][j-1] > grid[i][j]){
            num += solve(grid, dp, i, j-1)%mod;
            num %= mod;
        }
        return dp[i][j] = num;
    }
    
    bool valid(vector<vector<int>>& grid, int i, int j){
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
};