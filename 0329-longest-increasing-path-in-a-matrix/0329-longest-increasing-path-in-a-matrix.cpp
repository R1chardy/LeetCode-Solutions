class Solution {
public:
    int dp[201][201];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int len = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                len = max(len, solve(matrix, i, j));
            }
        }
        return len;
    }
    
    int solve(vector<vector<int>>& matrix, int i, int j){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int len = 1;
        if(valid(matrix, i+1, j) && matrix[i+1][j] > matrix[i][j]){
            len = max(len, 1+solve(matrix, i+1, j));
        }
        if(valid(matrix, i-1, j) && matrix[i-1][j] > matrix[i][j]){
            len = max(len, 1+solve(matrix, i-1, j));
        }
        if(valid(matrix, i, j+1) && matrix[i][j+1] > matrix[i][j]){
            len = max(len, 1+solve(matrix, i, j+1));
        }
        if(valid(matrix, i, j-1) && matrix[i][j-1] > matrix[i][j]){
            len = max(len, 1+solve(matrix, i, j-1));
        }
        return dp[i][j] = len;
    }
    
    bool valid(vector<vector<int>>& matrix, int i, int j){
        return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size();
    }
};