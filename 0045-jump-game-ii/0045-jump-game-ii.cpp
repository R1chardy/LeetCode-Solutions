class Solution {
public:
    vector<int> dp = vector<int>(10001, -1);
    int jump(vector<int>& nums, int pos = 0) {
        if(pos >= nums.size() - 1){
            return 0;
        }
        else if(dp[pos] != -1){
            return dp[pos];
        }
        int minJump = 10000000;
        for(int i = 1; i <= nums[pos]; i++){
            minJump = min(minJump, 1 + jump(nums, pos + i));
        }
        dp[pos] = minJump;
        return minJump;
    }
};