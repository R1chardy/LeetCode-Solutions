class Solution {
public:
    vector<int> dp = vector<int>(10000, -1);
    bool canJump(vector<int>& nums, int pos = 0) {
        if(pos == nums.size() - 1){
            return true;
        }
        else if(nums[pos] == 0){
            return false;
        }
        else if(dp[pos] != -1){
            return dp[pos] == 1;
        }
        else{
            for(int i = min(nums[pos] + pos, (int)nums.size() - 1) ; i >= pos + 1; i--){
                if(canJump(nums, i)){
                    dp[pos] = 1;
                    return true;
                }
            }
        }
        dp[pos] = 0;
        return false;
    }
};