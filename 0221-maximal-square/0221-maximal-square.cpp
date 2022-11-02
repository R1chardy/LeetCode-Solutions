class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxL = 0;
        int dp[matrix.size()][matrix[0].size()];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < matrix.size(); i++){
            dp[i][matrix[0].size()-1] = matrix[i][matrix[0].size()-1] - '0';
            maxL = max(maxL, dp[i][matrix[0].size()-1]);
        }
        for(int j = 0; j < matrix[0].size(); j++){
            dp[matrix.size()-1][j] = matrix[matrix.size()-1][j] - '0';
            maxL = max(maxL, dp[matrix.size()-1][j]);
        }
        for(int i = matrix.size()-2; i >= 0; i--){
            for(int j = matrix[0].size()-2; j >= 0; j--){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
                    maxL = max(maxL, dp[i][j]);
                }
            }
        }
        return maxL*maxL;
    }
};