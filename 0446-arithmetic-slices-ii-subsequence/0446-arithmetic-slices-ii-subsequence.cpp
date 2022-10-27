class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long sum = 0;
        vector<unordered_map<long long, long long>> dp(nums.size());
        for(long long i = 0; i < nums.size(); i++){
            for(long long j = 0; j < i; j++){
                long long diff = (long long)nums[i] - (long long)nums[j];
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