class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(5001, 0);
        dp[0] = 1;
        for(auto x : coins){
            for(int i = 1; i <= amount; i++){
                if(i - x >= 0){
                    dp[i] += dp[i-x];
                }
            }
        }
        return dp[amount];
    }
};