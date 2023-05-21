class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int mod = 1e9+7;
        vector<int> pre(nums.size());
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            pre[i] = sum;
        }
        int ans = 0;
        for(int i = 0; i < pre.size()-2; i++){
            auto it1 = lower_bound(pre.begin()+i+1, pre.end()-1, 2*pre[i]);
            auto it2 = upper_bound(it1, pre.end()-1, (pre[pre.size()-1]-pre[i])/2 + pre[i]);
            ans = (ans+it2-it1)%mod;
        }
        return ans;
    }
};