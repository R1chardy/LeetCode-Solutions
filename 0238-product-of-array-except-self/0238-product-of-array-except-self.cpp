class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 1);
        vector<int> suff(nums.size(), 1);
        vector<int> ret(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            pre[i] *= nums[i] * ((i == 0)? 1 : pre[i-1]);
            suff[nums.size() - 1 - i] *= nums[nums.size() - 1 - i] * ((i == 0)? 1 : suff[nums.size() - i]);
        }
        for(int i = 0; i < ret.size(); i++){
            ret[i] = (i == 0? 1 : pre[i-1]) * (i == ret.size() - 1? 1 : suff[i+1]);
        }
        return ret;
    }
};