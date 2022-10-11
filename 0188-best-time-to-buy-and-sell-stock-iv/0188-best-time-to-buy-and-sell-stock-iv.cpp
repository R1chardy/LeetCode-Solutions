class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int bought;
        int money;
        vector<int> dp(prices.size(), 0);
        for(int x = 0; x < k; x++){
            bought = INT_MAX;
            money = 0;
            for(int i = 0; i < prices.size(); i++){
                bought = min(bought, prices[i] - dp[i]);
                money = max(money, prices[i] - bought);
                dp[i] = money;
            }
        }
        return dp[prices.size() - 1];
    }
};