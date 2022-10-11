class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought;
        int money;
        vector<int> dp(prices.size(), 0);
        for(int x = 0; x < 2; x++){
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