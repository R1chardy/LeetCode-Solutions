class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // if(nums.size() < 2){
        //     return false;
        // }
        unordered_map<int, int> rems;
        rems[0] = -1;
        int pre = 0;
        for(int i = 0; i < nums.size(); i++){
            pre += nums[i];
            if(rems.find(pre%k) != rems.end() && i - rems[pre%k] > 1){
                return true;
            }
            //rems[pre%k] = i;
            rems[pre%k] = rems.find(pre%k) == rems.end()? i : rems[pre%k];
        }
        return false;
    }
};