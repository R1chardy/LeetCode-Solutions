class Solution {
public:
    int dp[201][201];
    int minFallingPathSum(vector<vector<int>>& grid) {
        int minV = INT_MAX;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < grid[0].size(); i++){
            minV = min(minV, solve(grid, 0, i));
        }
        return minV; 
    }
    
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return 40000;
        }
        else if(i >= grid.size()-1){
            return grid[i][j];
        }
        else if(dp[i][j] != -1){
            return dp[i][j];
        }
        int res = INT_MAX;
        for(int x = 0; x < grid[0].size(); x++){
            if(x != j){
                res = min(res, solve(grid, i+1, x));
            }
        }
        return dp[i][j] = grid[i][j] + res;
    }                  
};