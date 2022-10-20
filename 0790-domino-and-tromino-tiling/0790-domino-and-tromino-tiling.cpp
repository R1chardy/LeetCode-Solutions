class Solution {
public:
    long dp[1001] = {0};
    int numTilings(int n) {
        int mod = 1e9+7;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = 2*dp[i-1] + dp[i-3];
            dp[i] %= mod;
        }
        return dp[n];
    }
};