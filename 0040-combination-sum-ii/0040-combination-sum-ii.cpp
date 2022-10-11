class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans = {};
        vector<vector<int>> ret = {};
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, ans, ret);
        return ret;
    }
    
    bool dfs(vector<int>& candidates, int target,  vector<int>& ans, vector<vector<int>>& ret, 
            int currSum = 0, int ind = 0){
        if(currSum == target){
            return true;
        }
        else if(currSum > target){
            return false;
        }
        else{
            for(int i = ind; i < candidates.size(); i++){
                if(i != ind && candidates[i-1] == candidates[i]){
                    continue;
                }
                ans.push_back(candidates[i]);
                if(dfs(candidates, target, ans, ret, currSum + candidates[i], i+1)){
                    ret.push_back(ans);
                }
                ans.pop_back();
            }
        }
        return false;
    }
};