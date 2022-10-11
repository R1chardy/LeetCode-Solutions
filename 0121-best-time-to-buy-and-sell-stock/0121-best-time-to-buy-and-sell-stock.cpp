class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1){
            return 0;
        }
        vector<int> diff;
        for(int i = 0; i < prices.size() - 1; i++){
            diff.push_back(prices[i+1] - prices[i]);
        }
        int ret = maxSubArray(diff);
        return ret > 0? ret: 0;
    }
    
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = nums[0];
        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            if (currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};