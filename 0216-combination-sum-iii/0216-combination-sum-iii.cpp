class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans = {};
        vector<vector<int>> ret = {};
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        dfs(candidates, n, ans, ret, k);
        return ret;
    }
    
    bool dfs(vector<int>& candidates, int target,  vector<int>& ans, vector<vector<int>>& ret, int k, 
            int currSum = 0, int ind = 0){
        if(currSum == target && k == 0){
            return true;
        }
        else if(currSum == target && k != 0){
            return false;
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
                if(dfs(candidates, target, ans, ret, k-1, currSum + candidates[i], i+1)){
                    ret.push_back(ans);
                }
                ans.pop_back();
            }
        }
        return false;
    }
};