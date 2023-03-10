class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
            [](auto x, auto y){
                return x[0] == y[0]? x[1] < y[1] : x[0] >= y[0];
            });
        vector<int> dp;
        int len = 0;
        for(int i = 0; i < envelopes.size(); i++){
            int height = envelopes[i][1];
            int les = lower_bound(dp.begin(), dp.begin()+len, height, greater<int>())-dp.begin();
            if(les == len){
                dp.push_back(height);
                len++;
            }
            else{
                dp[les] = height;
            }
        }
        return dp.size();
    }
};