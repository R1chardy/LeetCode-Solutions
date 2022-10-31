class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int cMax = 0;
        for(int i = 0; i < (int)nums.size()-2; i++){
            cMax = max(cMax, nums[i]);
            if(cMax > nums[i+2]){
                return false;
            }
        }
        return true;
    }
};