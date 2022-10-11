class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<vector<double>> dp = vector<vector<double>>(k, vector<double>(nums.size(), 0));
        vector<int> prefix = vector<int>(nums.size(), 0);
        
        int pre = 0;
        for(int i = 0; i < nums.size(); i++){
            pre += nums[i];
            prefix[i] = pre;
            dp[0][i] = pre / (double)(i+1);
        }
        
        for(int i = 1; i < k; i++){
            for(int j = i; j < nums.size(); j++){
                for(int x = i-1; x < j; x++){
                    dp[i][j] = max(dp[i][j], dp[i-1][x] + (prefix[j] - prefix[x]) / (double)(j - x));
                }
            }
        }
        
        return dp[k-1][nums.size()-1];
    }
};