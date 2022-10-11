class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sums = vector<int>(20000, 0);
        for(auto x: nums){
            
            sums[x] += x;
        }
        
        int prev1 = sums[1];
        int prev2 = sums[0];
        int currMax;
        for(int i = 2; i < sums.size(); i++){
            currMax = max(prev2 + sums[i], prev1);
            prev2 = prev1;
            prev1 = currMax;
        }
        return currMax;
    }
};