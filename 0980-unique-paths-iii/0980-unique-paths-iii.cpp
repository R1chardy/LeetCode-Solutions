class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int si, sj, num;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    si = i;
                    sj = j;
                }
                if(grid[i][j] == 0){
                    num++;
                }
            }
        }
        return dfs(grid, si, sj, num, 0);
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j, int num, int count){
        if(grid[i][j] == 2){
            if(num == count){
                return 1;
            }
            else{
                return 0;
            }
        }
        int res = 0;
        grid[i][j] = -1;
        if(isValid(grid, i+1, j) && grid[i+1][j] != -1){
            res += dfs(grid, i+1, j, num, count+1);
        }
        if(isValid(grid, i-1, j) && grid[i-1][j] != -1){
            res += dfs(grid, i-1, j, num, count+1);
        }
        if(isValid(grid, i, j+1) && grid[i][j+1] != -1){
            res += dfs(grid, i, j+1, num, count+1);
        }
        if(isValid(grid, i, j-1) && grid[i][j-1] != -1){
            res += dfs(grid, i, j-1, num, count+1);
        }
        grid[i][j] = 0;
        return res;
    }
    
    bool isValid(vector<vector<int>>& grid, int i, int j){
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
};