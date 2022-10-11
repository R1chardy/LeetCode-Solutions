class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> islands = grid;
        int count = 0;
        for(int i = 0; i < islands.size(); i++){
            for(int j = 0; j < islands[0].size(); j++){
                if(islands[i][j] == '1'){
                    dfs(islands, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& islands, int i, int j){
        islands[i][j] = 0;
        if(j < islands[0].size() - 1 && islands[i][j+1] == '1'){
            dfs(islands, i, j+1);
        }
        if(i < islands.size() - 1 && islands[i+1][j] == '1'){
            dfs(islands, i+1, j);
        }
        if(j > 0 && islands[i][j-1] == '1'){
            dfs(islands, i, j-1);
        }
        if(i > 0 && islands[i-1][j] == '1'){
            dfs(islands, i-1, j);
        }
    }
};