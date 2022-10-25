class Solution {
public:
    bool dp[101][101][102];
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, false, sizeof(dp));
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            if(count >= 0){
                count += (grid[i][0] == '('? 1 : -1);
            }
            if(count >= 0){
                dp[i][0][count] = true;
            }
        }
        count = 0;
        for(int i = 0; i < grid[0].size(); i++){
            if(count >= 0){
                count += (grid[0][i] == '('? 1 : -1);
            }
            if(count >= 0){
                dp[0][i][count] = true;
            }
        }
        for(int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                if(grid[i][j] == '('){
                    for(int k = 0; k < 101; k++){
                        if(dp[i-1][j][k]){
                            dp[i][j][k+1] = true;
                        }
                        if(dp[i][j-1][k]){
                            dp[i][j][k+1] = true;
                        }
                    }
                }
                else{
                    for(int k = 1; k <= 101; k++){
                        if(dp[i-1][j][k]){
                            dp[i][j][k-1] = true;
                        }
                        if(dp[i][j-1][k]){
                            dp[i][j][k-1] = true;
                        }
                    }
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1][0];
    }
};