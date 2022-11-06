class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxL = INT_MIN, sum = 0;
        for(auto x : nums){
            sum += x;
            maxL = max(maxL, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxL;
    }
};