class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<pair<int,int>>> dp(matrix.size(), vector<pair<int,int>>(matrix[0].size(), {0,0}));
        if(matrix[0][0] == '1'){
            dp[0][0] = {1,1};
        }
        for(int i = 1; i < matrix.size(); i++){
            if(matrix[i][0] == '1'){
                dp[i][0] = {1+dp[i-1][0].first, 1};
            }
        }
        for(int j = 1; j < matrix[0].size(); j++){
            if(matrix[0][j] == '1'){
                dp[0][j] = {1, 1+dp[0][j-1].second};
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = {1+dp[i-1][j].first, 1+dp[i][j-1].second};
                }
            }
        }
        int num = 0;
        for(int i = matrix.size()-1; i >= 0; i--){
            for(int j = matrix[0].size()-1; j >= 0; j--){
                for(int k = 0; k < min(dp[i][j].first, dp[i][j].second); k++){
                    if(dp[i-k][j].second >= k+1 && dp[i][j-k].first >= k+1){
                        num = max(num, k+1);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return num*num;
    }
};