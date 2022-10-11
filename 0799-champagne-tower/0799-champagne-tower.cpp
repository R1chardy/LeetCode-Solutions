class Solution {
public:
    vector<vector<double>> dp = vector<vector<double>>(101, vector<double>(101,0));
    double champagneTower(int poured, int query_row, int query_glass) {
        dp[0][0] = (double)poured;
        int i = 1, j = 2;
        while(i != query_row + 1){
            for(int x = 0; x < j; x++){
                if(x == 0){
                    dp[i][x] += (dp[i-1][x] - 1) / 2 < 0? 0: (dp[i-1][x] - 1) / 2;
                }
                else if(x == j-1){
                    dp[i][x] += (dp[i-1][x-1] - 1) / 2 < 0? 0 : (dp[i-1][x-1] - 1) / 2;
                }
                else{
                    dp[i][x] += (dp[i-1][x] - 1) / 2 < 0? 0 : (dp[i-1][x] - 1) / 2;
                    dp[i][x] += (dp[i-1][x-1] - 1) / 2 < 0? 0 : (dp[i-1][x-1] - 1) / 2;
                }
                // for(int a = 0; a < 7; a++){
                //     for(int b = 0; b <= a; b++){
                //         cout << dp[a][b] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
            }
            i++;
            j++;
        }
        return dp[query_row][query_glass] > 1? 1 : dp[query_row][query_glass];
    }
};