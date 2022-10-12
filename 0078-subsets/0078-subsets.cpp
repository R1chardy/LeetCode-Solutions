class Solution {
public:
    vector<vector<int>> ret = {};
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        dfs(nums, ans);
        return ret;
    }
    
    void dfs(vector<int>& nums, vector<int>& ans, int idx = 0){
        if(idx >= nums.size()){
            ret.push_back(ans);
            return;
        }
        else{
            ans.push_back(nums[idx]);
            dfs(nums, ans, idx+1);
            ans.pop_back();
            dfs(nums, ans, idx+1);
        }
    }
};