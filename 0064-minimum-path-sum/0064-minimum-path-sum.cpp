class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
        return solve(grid, 0, 0, dp);
    }
    
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i >= grid.size() || j >= grid[0].size()){
            return 200*200;
        }
        else if(i == grid.size()-1 && j == grid[0].size()-1){
            return grid[i][j];
        }
        else if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = grid[i][j] + min(solve(grid, i+1, j, dp), solve(grid, i, j+1, dp));
    }
};