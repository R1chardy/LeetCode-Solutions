class Solution {
public:
    vector<int> ans = {};
    vector<vector<int>> ret = {};
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target);
        return ret;
    }
    
    bool dfs(vector<int>& candidates, int target, int currSum = 0, int ind = 0){
        if(currSum == target){
            return true;
        }
        else if(currSum > target){
            return false;
        }
        else{
            for(int i = ind; i < candidates.size(); i++){
                ans.push_back(candidates[i]);
                if(dfs(candidates, target, currSum + candidates[i], i)){
                    ret.push_back(ans);
                }
                ans.pop_back();
            }
        }
        return false;
    }
};