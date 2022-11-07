class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), 0));
        dp[0][0] = mat[0][0]? 10000 : 0;
        dp[mat.size()-1][mat[0].size()-1] = mat[mat.size()-1][mat[0].size()-1]? 10000 : 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j]){
                    if(i == 0 && j == 0){
                        continue;
                    }
                    if(i > 0 && j > 0){
                        dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                    }
                    else if(j > 0){
                        dp[i][j] = 1 + dp[i][j-1];
                    }
                    else{
                        dp[i][j] = 1 + dp[i-1][j];
                    }
                }
            }
        }
        for(int i = mat.size()-1; i >= 0; i--){
            for(int j = mat[0].size()-1; j >= 0; j--){
                if(mat[i][j]){
                    if(i == mat.size()-1 && j == mat[0].size()-1){
                        continue;
                    }
                    if(i < mat.size()-1 && j < mat[0].size()-1){
                        dp[i][j] = min(dp[i][j], 1 + min(dp[i+1][j], dp[i][j+1]));
                    }
                    else if(j < mat[0].size()-1){
                        dp[i][j] = min(dp[i][j], 1 + dp[i][j+1]);
                    }
                    else{
                        dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);
                    }
                }
            }
        }
        return dp;
    }
};