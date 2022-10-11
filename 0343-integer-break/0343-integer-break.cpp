class Solution {
public:
    int integerBreak(int n) {
        static vector<int> dp(59, -1);
        int maxP = 0;
        int temp;
        if(n == 1){
            return 1;
        }
        else if(dp[n] != -1){
            return dp[n];
        }
        else{
            for(int i = 1; i <= n/2; i++){
                temp = max(i * integerBreak(n - i), i * (n-i));
                if (temp > maxP){
                    maxP = temp;
                }
            }
            dp[n] = maxP;
            return maxP;
        }
    }
};