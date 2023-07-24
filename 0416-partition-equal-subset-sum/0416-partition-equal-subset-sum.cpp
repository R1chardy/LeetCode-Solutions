class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2){
            return false;
        }
        vector<bool> dp(sum/2+1, false);
        dp[0] = true;
        for(auto& num : nums){
            for(int i = dp.size()-1; i >= 0; i--){
                if(dp[i] && i+num <= sum/2){
                    dp[i+num] = true;
                }
            }
        
        }
        return dp[sum/2];
    }
};