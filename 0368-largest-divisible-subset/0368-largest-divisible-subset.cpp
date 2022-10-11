class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> sorted = nums;
        vector<int> ans;
        sort(sorted.begin(), sorted.end());
        int iMax = 0;
        int valMax;
        vector<int> dp = vector<int>(nums.size(), 1);
        for(int i = 1; i < sorted.size(); i++){
            for(int j = i-1; j >= 0; j--){
                if(sorted[j] % sorted[i] == 0 || sorted[i] % sorted[j] == 0){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    iMax = dp[i] > dp[iMax]? i : iMax;
                }
            }
        }
        
        ans.push_back(sorted[iMax]);
        valMax = dp[iMax] - 1;
        
        for(int i = iMax-1; i >= 0; i--){
            if(dp[i] == valMax && ans.back() % sorted[i] == 0){
                ans.push_back(sorted[i]);
                valMax--;
            }
        }
        return ans;
    }
};