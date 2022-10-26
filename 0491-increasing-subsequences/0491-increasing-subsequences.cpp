class Solution {
public:
    vector<vector<int>> ret;
    vector<int> ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(nums, 0);
        return ret;
    }
    
    void solve(vector<int>& nums, int idx){
        if(ans.size() >= 2 && ans[ans.size()-1] >= ans[ans.size()-2]){
            ret.push_back(ans);
        }
        unordered_set<int> has;
        for(int i = idx; i < nums.size(); i++){
            if((ans.empty() || nums[i] >= ans.back()) && has.count(nums[i]) == 0){
                ans.push_back(nums[i]);
                solve(nums, i+1);
                ans.pop_back();
                has.emplace(nums[i]);
            }
        }
    }
};