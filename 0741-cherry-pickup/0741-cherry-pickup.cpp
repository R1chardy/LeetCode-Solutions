class Solution {
public:
    int dp[51][51][51][51];
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int x = helper(grid, 0, 0, 0, 0);
        return x < 0? 0 : x;
    }
    
    int helper(vector<vector<int>>& grid, int r1, int c1, int r2, int c2){
        if(r1 < 0 || r1 >= grid.size() 
           || c1 < 0 || c1 >= grid.size() 
           || r2 < 0 || r2 >= grid.size() 
           || c2 < 0 || c2 >= grid.size() 
           || grid[r1][c1] == -1 
           || grid[r2][c2] == -1){
            return INT_MIN;
        }
        if(r1 == grid.size()-1 && c1 == grid.size()-1){
            return grid[r1][c1];
        }
        if(dp[r1][c1][r2][c2] != -1){
            return dp[r1][c1][r2][c2];
        }
        int count = 0;
        if(r1 == r2 && c1 == c2 && grid[r1][c1] == 1){
            count++;
        }
        else{
            if(grid[r1][c1] == 1){
                count++;
            }
            if(grid[r2][c2] == 1){
                count++;
            }
          
        }
        int a = helper(grid, r1, c1+1, r2, c2+1);
        int b = helper(grid, r1, c1+1, r2+1, c2);
        int c = helper(grid, r1+1, c1, r2, c2+1);
        int d = helper(grid, r1+1, c1, r2+1, c2);
        return dp[r1][c1][r2][c2] = count + max(max(a,b), max(c,d));
    }
};