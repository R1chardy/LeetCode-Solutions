class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sum = 0;
        vector<unordered_map<long,long>> dp(nums.size());
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                long diff = (long)nums[i] - (long)nums[j];
                dp[i][diff] += 1;
                if(dp[j].count(diff) != 0){
                    sum += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        return sum;
    }
};