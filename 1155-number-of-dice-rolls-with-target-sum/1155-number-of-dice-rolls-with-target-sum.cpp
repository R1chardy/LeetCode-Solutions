class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9+7;
        long dp[31][2001] = {0};
        for(int i = 0; i < k; i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i < 31; i++){
            for(int j = i; j < 2001; j++){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % mod;
                dp[i][j] -= j-k-1 < 0? 0 : dp[i-1][j-k-1];
                if(dp[i][j] < 0){
                    dp[i][j] += mod;
                }
            }
        }
        return dp[n-1][target-1]%mod;
    }
};