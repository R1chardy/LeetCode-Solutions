class Solution {
public:
    vector<vector<int>> ret;
    vector<int> ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(nums, 0);
        return ret;
    }
    
    void solve(vector<int>& nums, int idx){
        if(ans.size() >= 2){
            ret.push_back(ans);
        }
        unordered_set<int> done;
        for(int i = idx; i < nums.size(); i++){
            if(done.count(nums[i])){
                continue;
            }
            if(ans.size() == 0 || nums[i] >= ans[ans.size()-1]){
                ans.push_back(nums[i]);
                solve(nums, i+1);
                ans.pop_back();
                done.emplace(nums[i]);
            }
        }
    }
};