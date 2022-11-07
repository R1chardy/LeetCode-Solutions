class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size()-2; i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j < nums.size()-1; j++){
                if(j != i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                if(binary_search(nums.begin()+j+1, nums.end(), -1*(nums[i] + nums[j]))){
                    ans.push_back({nums[i], nums[j], -1*(nums[i] + nums[j])});
                }
            }
        }
        return ans;
    }
};