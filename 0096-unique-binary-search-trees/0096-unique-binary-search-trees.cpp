class Solution {
public:
    int dp[20] = {0};
    int numTrees(int n) {
        if(n <= 1){
            return 1;
        }
        else if(dp[n] != 0){
            return dp[n];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += numTrees(i) * numTrees(n-i-1);
        }
        return dp[n] = ans;
    }
};