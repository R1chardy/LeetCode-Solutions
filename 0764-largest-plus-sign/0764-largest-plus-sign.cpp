class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int grid[n][n];
        int up[n][n];
        int down[n][n];
        int left[n][n];
        int right[n][n];
        memset(grid, 1, sizeof(grid));
        memset(up, 0, sizeof(up));
        memset(down, 0, sizeof(down));
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        
        for(auto x : mines){
            grid[x[0]][x[1]] = 0;
        }
        int pre, pre2;
        for(int i = 0; i < n; i++){
            pre = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    pre++;
                }
                else{
                    pre = 0;
                }
                left[i][j] = pre;
            }
            pre2 = 0;
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j]){
                    pre2++;
                }
                else{
                    pre2 = 0;
                }
                right[i][j] = pre2;
            }
        }
        for(int j = 0; j < n; j++){
            pre = 0;
            for(int i = 0; i < n; i++){
                if(grid[i][j]){
                    pre++;
                }
                else{
                    pre = 0;
                }
                up[i][j] = pre;
            }
            pre2 = 0;
            for(int i = n-1; i >= 0; i--){
                if(grid[i][j]){
                    pre2++;
                }
                else{
                    pre2 = 0;
                }
                down[i][j] = pre2;
            }
        }
        int maxL = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                maxL = max(maxL, min(min(left[i][j], right[i][j]), min(up[i][j], down[i][j])));
            }
        }
        return maxL;
    }
};