class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int dp[1001][1001] = {};
        for(int i = 0; i < 1001; i++){
            for(int j = 0; j < 1001; j++){
                dp[i][j] = 1;
            }
        }
        int maxL = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                dp[i][nums[i]-nums[j]+500] = max(dp[i][nums[i]-nums[j]+500], 1 + dp[j][nums[i]-nums[j]+500]);
                maxL = max(maxL, dp[i][nums[i]-nums[j]+500]);
            }
        }
        return maxL;
    }
};