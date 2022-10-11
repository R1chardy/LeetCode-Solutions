class Solution {
public:
    vector<vector<pair<bool,pair<bool, bool>>>> dp;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        
        vector<pair<bool, pair<bool, bool>>> maker(heights[0].size(), {false, {false, false}});
        for(int i = 0; i < heights.size(); i++){
            dp.push_back(maker);
        }
        
        vector<vector<int>> chart = heights;
        vector<vector<int>> ret;
        pair<bool, bool> temp;
        vector<int> push;
        for(int i = 0; i < chart.size(); i++){
            for(int j = 0; j < chart[0].size(); j++){
                temp = dfs(chart, i, j);
                dp[i][j] = {true, temp};
                chart = heights;
                if(temp.first && temp.second){
                    push.push_back(i);
                    push.push_back(j);
                    ret.push_back(push);
                    push.clear();
                }
            }
        }
        return ret;
    }
    
    pair<bool, bool> dfs(vector<vector<int>>& heights, int i, int j){
        pair<bool, bool> ret = {false, false}, temp = {false, false};
        int val = heights[i][j];
        heights[i][j] = 100001;
        if(i == 0 || j == 0){
            ret.first = true;
        }
        if(i == heights.size() - 1 || j == heights[0].size() - 1){
            ret.second = true;
        }
        if(ret.first && ret.second){
            return ret;
        }
        if(dp[i][j].first){
            return dp[i][j].second;
        }
        //Recurse
        if(i > 0 && val >= heights[i-1][j]){
            temp = dfs(heights, i-1, j);
            ret.first = ret.first || temp.first;
            ret.second = ret.second || temp.second;
        }
        if(i < heights.size() - 1 && val >= heights[i+1][j]){
            temp = dfs(heights, i+1, j);
            ret.first = ret.first || temp.first;
            ret.second = ret.second || temp.second;
        }
        if(j > 0 && val >= heights[i][j-1]){
            temp = dfs(heights, i, j-1);
            ret.first = ret.first || temp.first;
            ret.second = ret.second || temp.second;
        }
        if(j < heights[0].size() - 1 && val >= heights[i][j+1]){
            temp = dfs(heights, i, j+1);
            ret.first = ret.first || temp.first;
            ret.second = ret.second || temp.second;
        }
        return ret;
    }
};