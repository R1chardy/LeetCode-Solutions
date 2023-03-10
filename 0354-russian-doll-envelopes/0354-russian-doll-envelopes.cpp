class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
            [](auto x, auto y){
                return x[0] == y[0]? x[1] > y[1] : x[0] < y[0];
            });
        vector<int> dp;
        for(int i = 0; i < envelopes.size(); i++){
            int height = envelopes[i][1];
            int les = lower_bound(dp.begin(), dp.end(), height)-dp.begin();
            if(les == dp.size()){
                dp.push_back(height);
            }
            else{
                dp[les] = height;
            }
        }
        return dp.size();
    }
};