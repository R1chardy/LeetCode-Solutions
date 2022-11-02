class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int grid[n][n];
        int dp[n][n];
        memset(grid, 1, sizeof(grid));
        fill_n(&dp[0][0], n*n, INT_MAX);
        for(auto x : mines){
            grid[x[0]][x[1]] = 0;
        }
        int pre, pre2;
        for(int i = 0; i < n; i++){
            pre = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    pre++;
                }
                else{
                    pre = 0;
                }
                dp[i][j] = min(dp[i][j], pre);
            }
            pre2 = 0;
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j]){
                    pre2++;
                }
                else{
                    pre2 = 0;
                }
                dp[i][j] = min(dp[i][j], pre2);
            }
        }
        for(int j = 0; j < n; j++){
            pre = 0;
            for(int i = 0; i < n; i++){
                if(grid[i][j]){
                    pre++;
                }
                else{
                    pre = 0;
                }
                dp[i][j] = min(dp[i][j], pre);
            }
            pre2 = 0;
            for(int i = n-1; i >= 0; i--){
                if(grid[i][j]){
                    pre2++;
                }
                else{
                    pre2 = 0;
                }
                dp[i][j] = min(dp[i][j], pre2);
            }
        }
        int maxL = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                maxL = max(maxL, dp[i][j]);
            }
        }
        return maxL;
    }
};