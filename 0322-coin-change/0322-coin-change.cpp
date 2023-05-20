class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        vector<long> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(auto& coin : coins){
            if(coin < amount+1){
                dp[coin] = 1;
            }
        }
        for(int i = 0; i < amount+1; i++){
            for(auto& coin : coins){
                if(i-coin > 0){
                    dp[i] = min(dp[i], 1+dp[i-coin]);
                }
            }
        }
        return dp[amount] == INT_MAX? -1 : dp[amount];
    }
};