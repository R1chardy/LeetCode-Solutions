class Solution {
public:
    
    double knightProbability(int n, int k, int row, int column) {
        int xOff[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        int yOff[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        double dp[26][26][101];
        memset(dp, 0, sizeof(dp));
        dp[row][column][0] = 1.0;
        for(int l = 1; l <= k; l++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    for(int x = 0; x < 8; x++){
                        if(i+yOff[x] >= 0 && i+yOff[x] < n 
                           && j+xOff[x] >= 0 && j+xOff[x] < n 
                           && dp[i+yOff[x]][j+xOff[x]][l-1] != 0){
                            dp[i][j][l] += dp[i+yOff[x]][j+xOff[x]][l-1] * 0.125;
                        }
                    }
                }
            }
        }
        double sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += dp[i][j][k];
            }
        }
        return sum;
    }
};