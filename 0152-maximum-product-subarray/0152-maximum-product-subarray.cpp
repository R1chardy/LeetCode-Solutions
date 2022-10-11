class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret;
        if(nums.size() == 1){
            return nums[0];
        }
        vector<pair<int, int>> dp(nums.size(), {0,0});  //Pair of max and min
        int maxV = *max_element(nums.begin(), nums.end()), minV = *min_element(nums.begin(), nums.end()), currMax, currMin;
        dp[0] = {nums[0], nums[0]};
        for(int i = 1; i < nums.size(); i++){
            currMax = dp[i-1].first * nums[i];
            currMin = dp[i-1].second * nums[i];
            dp[i].first = max(currMax, nums[i]);
            dp[i].first = max(dp[i].first, currMin);
            dp[i].second = min(currMin, nums[i]);
            dp[i].second = min(dp[i].second, currMax);
            maxV = max(maxV, dp[i].first);
            minV = min(minV, dp[i].second);
        }
        return maxV;
    }
};