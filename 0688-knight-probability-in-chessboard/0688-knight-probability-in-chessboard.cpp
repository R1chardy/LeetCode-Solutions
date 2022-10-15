class Solution {
public:
    int xOff[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int yOff[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    double dp[26][26][101] = {};
    double knightProbability(int n, int k, int row, int column, double curr = 1.0) {
        if(curr == 1.0){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    for(int k = 0; k < 101; k++){
                        dp[i][j][k] = -1;
                    }
                }
            }
        }
        if(!isInBoard(n, row, column)){
            return 0;
        }
        else if(k == 0){
            return curr;
        }
        else if(dp[row][column][k] != -1){
            return dp[row][column][k];
        }
        else{
            double sum = 0.0;
            for(int i = 0; i < 8; i++){
                sum += knightProbability(n, k-1, row+yOff[i], column+xOff[i], curr*0.125);
            }
            return dp[row][column][k] = sum;
        }
    }
    
    bool isInBoard(int n, int i, int j){
        return i >= 0 && i < n && j >= 0 && j < n;
    }
};