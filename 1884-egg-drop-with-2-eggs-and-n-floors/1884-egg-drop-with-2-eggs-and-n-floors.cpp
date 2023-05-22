class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return egg(n, 2, dp);
    }
    
    int egg(int n, int k, vector<vector<int>>& dp){
        if(k == 1){
            return n;
        }
        else if(n == 1){
            return 1;
        }
        else if(n == 0){
            return 0;
        }
        else if(dp[n][k] != -1){
            return dp[n][k];
        }
        else{
            int ans = INT_MAX;
            for(int i = 1; i <= n; i++){
                ans = min(ans, max(egg(n-i, k, dp), egg(i-1, k-1, dp)));
            }
            return dp[n][k] = 1+ans;
        }
    }
};