class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        unordered_map<int,int> val2idx;
        for(int i = 0; i < nums.size(); i++){
            val2idx[nums[i]] = i;
        }
        for(int i = 0; i < nums.size()-2; i++){
            if(nums[i] > 0){
                break;
            }
            for(int j = i+1; j < nums.size()-1; j++){
                if(val2idx.count(-nums[i]-nums[j]) && val2idx[-nums[i]-nums[j]] > j){
                    ans.push_back({nums[i], nums[j], -nums[i]-nums[j]});
                }
                j = val2idx[nums[j]];
            }
            i = val2idx[nums[i]];
        }
        return ans;
    }
};