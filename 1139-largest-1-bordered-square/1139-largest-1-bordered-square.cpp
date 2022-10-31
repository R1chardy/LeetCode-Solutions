class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        vector<vector<pair<int,int>>> dp(grid.size(), vector<pair<int,int>>(grid[0].size(), {0,0}));
        if(grid[0][0]){
            dp[0][0] = {1,1};
        }
        for(int i = 1; i < grid.size(); i++){
            if(grid[i][0]){
                dp[i][0] = {1+dp[i-1][0].first, 1};
            }
        }
        for(int j = 1; j < grid[0].size(); j++){
            if(grid[0][j]){
                dp[0][j] = {1, 1+dp[0][j-1].second};
            }
        }
        for(int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                if(grid[i][j]){
                    dp[i][j] = {1+dp[i-1][j].first, 1+dp[i][j-1].second};
                }
            }
        }
        int num = 0;
        for(int i = grid.size()-1; i >= 0; i--){
            for(int j = grid[0].size()-1; j >= 0; j--){
                for(int k = min(dp[i][j].first, dp[i][j].second); k > 0 && k > num; k--){
                    if(dp[i-k+1][j].second >= k && dp[i][j-k+1].first >= k){
                        num = k;
                        break;
                    }
                }
            }
        }
        return num*num;
    }
};