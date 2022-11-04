class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> diffs;
        for(int i = 1; i < prices.size(); i++){
            diffs.push_back(prices[i] - prices[i-1]);
        }
        int maxS = 0, currS = 0;
        for(int i = 0; i < diffs.size(); i++){
            currS += diffs[i];
            maxS = max(maxS, currS);
            if(currS < 0){
                currS = 0;
            }
        }
        return maxS;
    }
};