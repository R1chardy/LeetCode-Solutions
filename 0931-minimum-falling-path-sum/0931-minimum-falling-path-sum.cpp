class Solution {
public:
    int dp[101][101];
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minV = INT_MAX;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < matrix[0].size(); i++){
            minV = min(minV, solve(matrix, 0, i));
        }
        return minV; 
    }
    
    int solve(vector<vector<int>>& matrix, int i, int j){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()){
            return 10100;
        }
        else if(i == matrix.size()-1){
            return matrix[i][j];
        }
        else if(dp[i][j] != -1){
            return dp[i][j];
        }
        int a = solve(matrix, i+1, j-1);
        int b = solve(matrix, i+1, j);
        int c = solve(matrix, i+1, j+1);
        return dp[i][j] = matrix[i][j] + min(a,min(b,c));
    }                  
};