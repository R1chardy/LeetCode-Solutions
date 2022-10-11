class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> iMap;
        for(int i = 0; i < nums.size(); i++){
            iMap[nums[i]] = i;
        }
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(iMap[-(nums[i] + nums[j])] && iMap[-(nums[i] + nums[j])] > j){
                    res.push_back({nums[i], nums[j], -(nums[i] + nums[j])});
                }
                j = iMap[nums[j]];
            }
            i = iMap[nums[i]];
        }
        return res;
    }
};