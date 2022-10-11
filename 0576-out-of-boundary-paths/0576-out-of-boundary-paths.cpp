class Solution {
public:
    long dp[51][51][51] = {};
    long MOD = 1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        for(int i = 0; i < m; i++){
            dp[i][0][1] += 1;
            dp[i][n-1][1] += 1;
        }
        for(int i = 0; i < n; i++){
            dp[0][i][1] += 1;
            dp[m-1][i][1] += 1;
        }
        for(int k = 2; k <= maxMove; k++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    dp[i][j][k] += dp[i+1][j][k-1] + dp[i][j+1][k-1] + dp[i][j][1];
                    dp[i][j][k] %= MOD;
                    if(i > 0){
                        dp[i][j][k] += dp[i-1][j][k-1];
                        dp[i][j][k] %= MOD;
                    }
                    if(j > 0){
                        dp[i][j][k] += dp[i][j-1][k-1];
                        dp[i][j][k] %= MOD;
                    }
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
};