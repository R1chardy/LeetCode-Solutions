class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k+1, -1)));
        return helper(grid, k, 0, 0, 0, dp);
    }
    
    int helper(vector<vector<int>>& grid, int k, int currSum, int i, int j, vector<vector<vector<int>>>& dp){
        int mod = 1e9+7;
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return 0;
        }
        else if(i == grid.size()-1 && j == grid[0].size()-1){
            if((currSum + grid[i][j])%k == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else if(dp[i][j][(currSum + grid[i][j])%k] != -1){
            return dp[i][j][(currSum + grid[i][j])%k];
        }
        return dp[i][j][(currSum + grid[i][j])%k] = (helper(grid, k, (currSum + grid[i][j])%k, i+1, j, dp)%mod 
                + helper(grid, k, (currSum + grid[i][j])%k, i, j+1, dp)%mod)%mod;
    }
};