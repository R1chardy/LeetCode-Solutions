class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        int i = 0, j = 0, k = 0;
        for(int z = 1; z < n; z++){
            dp[z] = min(dp[i]*2, min(dp[j]*3, dp[k]*5));
            if(dp[i]*2 == dp[z]){
                i++;
            }
            if(dp[j]*3 == dp[z]){
                j++;
            }
            if(dp[k]*5 == dp[z]){
                k++;
            }
        }
        return dp[n-1];
    }
};