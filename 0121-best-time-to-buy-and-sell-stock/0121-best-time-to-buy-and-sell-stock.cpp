class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0], diff = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i]-mn > diff){
                diff = prices[i]-mn;
            }
            mn = min(prices[i], mn);
        }
        return diff;
    }
};