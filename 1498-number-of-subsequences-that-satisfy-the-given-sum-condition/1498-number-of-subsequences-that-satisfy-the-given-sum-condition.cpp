class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1, ans = 0, mod = 1e9+7;
        vector<int> pows(nums.size()+1,1);
        for(int i = 1; i <= nums.size(); i++){
            pows[i] = (pows[i-1]*2)%mod;
        }
        while(l <= r){
            if(nums[l] + nums[r] > target){
                r--;
            }else{
                ans = (ans+pows[r-l])%mod;
                l++;
            }
        }
        return ans;
    }
};