class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int temp = 0;
        for(auto& i : nums){
            temp ^= i;
            ans.push_back((~temp)&((1<<maximumBit)-1));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};