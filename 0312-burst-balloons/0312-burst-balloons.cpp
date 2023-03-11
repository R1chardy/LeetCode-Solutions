class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(nums, 0, nums.size()-1, 1, 1, dp);
    }
    
    int solve(vector<int>& nums, int l, int r, int leftB, int rightB, vector<vector<int>>& dp){
        if(r < l){
            return 0;
        }
        else if(r == l){
            return nums[r] * leftB * rightB;
        }
        else if(dp[l][r] != -1){
            return dp[l][r];
        }
        else{
            for(int i = l; i <= r; i++){
                dp[l][r] = max(dp[l][r], nums[i] * leftB * rightB + solve(nums, i+1, r, nums[i], rightB, dp)
                    + solve(nums, l, i-1, leftB, nums[i], dp));
            }
            return dp[l][r];
        }
    }
};