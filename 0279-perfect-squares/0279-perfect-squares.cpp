class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp(10001, 1000000);
        vector<int> squares;
        int minV;
        for(int i = 1; i*i < 10000; i++){
            dp[i*i] = 1;
            squares.push_back(i*i);
        }
        for(int i = 1; i <= n; i++){
            minV = dp[i];
            for(auto x : squares){
                if(i - x >= 0){
                    if(1 + dp[i-x] < minV){
                        minV = 1 + dp[i-x];
                    }
                }
            }
            dp[i] = minV;
        }
        return dp[n];
    }
};