class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minV = INT_MAX, maxV = 0;
        for(auto x : prices){
            minV = min(minV, x);
            maxV = max(maxV, x - minV);
        }
        return maxV;
    }
};