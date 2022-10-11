class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        map<int, int> colors;
        int color = 2;
        int size, currA, maxA = -1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    colors.emplace(color, floodfill(grid, color, i, j));
                    color++;
                }
            }
        }
        vector<int> seen;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    currA = 1;
                    seen.clear();
                    if(i > 0 && grid[i-1][j] != 0 
                        && find(seen.begin(), seen.end(), grid[i-1][j]) == seen.end()){
                        currA += colors[grid[i-1][j]];
                        seen.push_back(grid[i-1][j]);
                    }
                    if(i < grid.size() - 1 && grid[i+1][j] != 0 
                        && find(seen.begin(), seen.end(), grid[i+1][j]) == seen.end()){
                        currA += colors[grid[i+1][j]];
                        seen.push_back(grid[i+1][j]);
                    }
                    if(j > 0 && grid[i][j-1] != 0 
                        && find(seen.begin(), seen.end(), grid[i][j-1]) == seen.end()){
                        currA += colors[grid[i][j-1]];
                        seen.push_back(grid[i][j-1]);
                    }
                    if(j < grid[0].size() - 1 && grid[i][j+1] != 0 
                        && find(seen.begin(), seen.end(), grid[i][j+1]) == seen.end()){
                        currA += colors[grid[i][j+1]];
                        seen.push_back(grid[i][j+1]);
                    }
                    maxA = max(maxA, currA);
                }
            }
        }
        return maxA == -1? (grid.size())*(grid[0].size()) : maxA;
    }
    
    int floodfill(vector<vector<int>>& grid, int val, int i, int j){
        int count = 1;
        grid[i][j] = val;
        if(i > 0 && grid[i-1][j] == 1){
            count += floodfill(grid, val, i-1, j);
        }
        if(i < grid.size() - 1 && grid[i+1][j] == 1){
            count += floodfill(grid, val, i+1, j);
        }
        if(j > 0 && grid[i][j-1] == 1){
            count += floodfill(grid, val, i, j-1);
        }
        if(j < grid[0].size() - 1 && grid[i][j+1] == 1){
            count += floodfill(grid, val, i, j+1);
        }
        return count;
    }
};