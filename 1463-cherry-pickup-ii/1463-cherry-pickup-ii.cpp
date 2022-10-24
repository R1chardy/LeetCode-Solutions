class Solution {
public:
    int dp[71][71][71];
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return helper(grid, 0, 0, grid[0].size()-1);
    }
    
    int helper(vector<vector<int>>& grid, int r1, int c1, int c2){
        if(r1 < 0 || r1 >= grid.size() || c1 < 0 || c1 >= grid[0].size() 
           || c2 < 0 || c2 >= grid[0].size()){
            return 0;
        }
        else if(r1 == grid.size()-1){
            if(c1 == c2){
                return grid[r1][c1];
            }
            else{
                return grid[r1][c1] + grid[r1][c2];
            }
        }
        else if(dp[r1][c1][c2] != -1){
            return dp[r1][c1][c2];
        }
        int ret = 0;
        if(c1 == c2){
            ret += grid[r1][c1];
        }
        else{
            ret += grid[r1][c1] + grid[r1][c2];
        }
        int a = helper(grid, r1+1, c1-1, c2-1);
        int b = helper(grid, r1+1, c1-1, c2);
        int c = helper(grid, r1+1, c1-1, c2+1);
        int d = helper(grid, r1+1, c1, c2-1);
        int e = helper(grid, r1+1, c1, c2);
        int f = helper(grid, r1+1, c1, c2+1);
        int g = helper(grid, r1+1, c1+1, c2-1);
        int h = helper(grid, r1+1, c1+1, c2);
        int i = helper(grid, r1+1, c1+1, c2+1);
        return dp[r1][c1][c2] = ret + max(max(max(max(a,b), max(c,d)), max(max(e,f), max(g,h))), i);
    }
};