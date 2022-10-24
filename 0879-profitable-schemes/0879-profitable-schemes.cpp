class Solution {
public:
    int dp[101][101][101];
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return helper(n, minProfit, group, profit, 0, 0);
    }
    
    int helper(int n, int minProfit, vector<int>& group, vector<int>& profit, int idx, int maxP){
        int mod = 1e9+7;
        if(idx >= group.size()){
            if(n >= 0){
                return maxP >= minProfit;
            }
            else{
                return 0;
            }
        }
        else if(dp[n][idx][maxP] != -1){
            return dp[n][idx][maxP];
        }
        long res = 0;
        if(n >= group[idx]){
            res += helper(n-group[idx], minProfit, group, profit, idx+1, min(maxP + profit[idx], minProfit))%mod;
        }
        res += helper(n, minProfit, group, profit, idx+1, maxP)%mod;
        res %= mod;
        return dp[n][idx][maxP] = res;
    }
};