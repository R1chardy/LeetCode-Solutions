class Solution {
public:
    int rob(vector<int>& nums) {
        int take = 0, skip = 0, temp;
        for(auto x : nums){
            temp = max(take+x, skip);
            take = skip;
            skip = temp;
        }
        return max(take, skip);
    }
};