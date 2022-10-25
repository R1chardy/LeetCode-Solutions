class Solution {
public:
    int dp[101][101][202];
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, 0);
    }
    
    bool solve(vector<vector<char>>& grid, int i, int j, int sum){
        int val = sum + ((grid[i][j] == '(')? 1 : -1);
        if(val < 0){
            return false;
        }
        else if(i == grid.size()-1 && j == grid[0].size()-1){
            if(val == 0){
                return true;
            }
            else{
                return false;
            }
        }
        else if(dp[i][j][val] != -1){
            return dp[i][j][val];
        }
        else{
            bool ret = false;
            if(i+1 < grid.size()){
                ret = ret || solve(grid, i+1, j, val);
            }
            if(j+1 < grid[0].size()){
                ret = ret || solve(grid, i, j+1, val);
            }
            return dp[i][j][val] = ret;
        }
    }
};