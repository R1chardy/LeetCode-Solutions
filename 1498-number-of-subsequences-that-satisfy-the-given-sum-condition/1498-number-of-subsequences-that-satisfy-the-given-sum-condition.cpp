class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9+7;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        long ans = 0;
        vector<int> pows(nums.size()+1,1);
        for(int i = 1; i <= nums.size(); i++){
            pows[i] = (pows[i-1] * 2)%mod;
        }
        while(l <= r){
            while(r >= 0 && nums[l] + nums[r] > target){
                r--;
            }
            if(l > r || r < 0){
                continue;
            }
            ans += pows[r-l];
            ans %= mod;
            l++;
        }
        return ans;
    }
};