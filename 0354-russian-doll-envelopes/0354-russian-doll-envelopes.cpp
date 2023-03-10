class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
            [](auto x, auto y){
                return x[0] == y[0]? x[1] > y[1] : x[0] < y[0];
            });
        vector<int> dp;
        for(auto& env : envelopes){
            int height = env[1];
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