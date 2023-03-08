class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int minC = INT_MAX;
        vector<int> dp(grid.size() * grid[0].size(), -1);
        for(int i = 0; i < grid[0].size(); i++){
            minC = min(minC, solve(dp, grid, moveCost, 0, grid[0][i]));
        }
        return minC;
    }
    
    int solve(vector<int>& dp, vector<vector<int>>& grid, vector<vector<int>>& moveCost, int layer, int node){
        if(layer >= grid.size()-1){
            return node;
        }
        else if(dp[node] != -1){
            return dp[node];
        }
        int minC = INT_MAX;
        for(int i = 0; i < moveCost[node].size(); i++){
            minC = min(minC, node + moveCost[node][i] + solve(dp, grid, moveCost, layer+1, grid[layer+1][i]));
        }
        return dp[node] = minC;
    }
};