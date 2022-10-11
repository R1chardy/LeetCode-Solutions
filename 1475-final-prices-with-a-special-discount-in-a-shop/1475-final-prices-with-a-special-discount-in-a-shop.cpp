class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result = prices;
        stack<int> leStack;
        for(int i = 0; i < prices.size(); i ++){
            while(!leStack.empty() && prices[i] <= prices[leStack.top()]){
                result[leStack.top()] = prices[leStack.top()] - prices[i];
                leStack.pop();
            }
            leStack.push(i);
        }
        return result;
    }
};