class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> iMap; //num to index
        for(int i = 0; i < nums.size(); i++){
            if(iMap.count(target - nums[i])){
                return {i, iMap[target-nums[i]]};
            }
            else{
                iMap[nums[i]] = i;
            }
        }
        return {0, 0};
    }
};