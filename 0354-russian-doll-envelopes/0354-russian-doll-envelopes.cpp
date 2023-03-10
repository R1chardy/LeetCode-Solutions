class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
            [](auto x, auto y){
                return x[0] == y[0]? x[1] < y[1] : x[0] >= y[0];
            });
        int w = envelopes[0][0];
        int h = envelopes[0][1];
        vector<int> dp(envelopes.size(), 0);
        int len = 0;
        for(int i = 0; i < envelopes.size(); i++){
            int les = lower_bound(dp.begin(), dp.begin()+len, envelopes[i][1], greater<int>())-dp.begin();
            if(les == len){
                len++;
            }
            dp[les] = envelopes[i][1];
        }
        return len;
    }
};