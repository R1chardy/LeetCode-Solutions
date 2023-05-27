class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 || nums.size() == 1){
            return false;
        }
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum/2+1, false));
        for(int i = 0; i < nums.size(); i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 1; j <= sum/2; j++){
                if(j < nums[i]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[nums.size()-1][sum/2];
    }
};