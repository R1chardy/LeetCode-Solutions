class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> iMap;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
            if(iMap.count(target - nums[i])){
                ret.push_back(i);
                ret.push_back(iMap[target - nums[i]]);
                return ret;
            }
            else{
                iMap[nums[i]] = i;
            }
        }
        return ret;
    }
};