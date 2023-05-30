class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, sum = 0, minL = INT_MAX;
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum >= target){
                minL = min(minL, j-i+1);
                sum  -= nums[i];
                i++;
            }
        }
        return minL == INT_MAX? 0 : minL;
    }
};