class Solution {
public:
    vector<unsigned int> dp = vector<unsigned int>(1000, 0);
    int combinationSum4(vector<int>& nums, int target) {
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= target; i++){
            int j = 0;
            while(j < nums.size() && nums[j] <= i){
                dp[i] += dp[i - nums[j]];
                j++;
            }
        }
        return dp[target];
    }
};