class Solution {
public:
    int tribonacci(int n) {
        static vector<int> dp(38, -1);
        if(n == 0){
            return 0;
        }
        else if(n == 1 || n == 2){
            return 1;
        }
        else if(dp[n] != -1){
            return dp[n];
        }
        else{
            return dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        }
    }
};