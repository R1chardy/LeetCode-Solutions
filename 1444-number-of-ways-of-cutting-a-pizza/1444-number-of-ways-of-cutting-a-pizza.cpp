class Solution {
public:
    int appRem[51][51] = {0};
    int dp[51][51][11] = {0};
    int ways(vector<string>& pizza, int k) {
        for(int i = 0; i < 51; i++){
            for(int j = 0; j < 51; j++){
                for(int k = 0; k < 11; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        
        appRem[pizza.size()-1][pizza[0].size()-1] = pizza[pizza.size()-1][pizza[0].size()-1] == 'A'? 1 : 0;
        
        for(int i = pizza[0].length()-2; i >= 0; i--){
            appRem[pizza.size()-1][i] = appRem[pizza.size()-1][i+1];
            appRem[pizza.size()-1][i] += pizza[pizza.size()-1][i] == 'A'? 1 : 0;
        }
        
        for(int i = pizza.size()-2; i >= 0; i--){
            appRem[i][pizza[0].length()-1] = appRem[i+1][pizza[0].length()-1];
            appRem[i][pizza[0].length()-1] += pizza[i][pizza[0].length()-1] == 'A'? 1 : 0;
        }
        
        for(int i = pizza.size()-2; i >= 0; i--){
            for(int j = pizza[0].length()-2; j >= 0; j--){
                appRem[i][j] = appRem[i][j+1] + appRem[i+1][j] - appRem[i+1][j+1];
                appRem[i][j] += pizza[i][j] == 'A'? 1 : 0;
            }
        }
        
        return dfs(pizza, k);
    }
    
    int dfs(vector<string>& pizza, int k, int i = 0, int j = 0){
        
        // cout << i << " " << j << " " << k << endl;
        if(k > appRem[i][j]){
            // cout << "impossible" << endl;
            return 0;
        }
        else if(k == 1 && appRem[i][j] > 0){
            // cout << "base case" << endl;
            return 1;
        }
        else if(k == 1){
            // cout << "impossible" << endl;
            return 0;
        }
        else if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        else{
            int mod = 1e9+7;
            long sum = 0;
            //horizontal cuts
            for(int x = i+1; x < pizza.size(); x++){
                if(appRem[i][j] - appRem[x][j] > 0){
                    // cout << i << " " << j << "cutting horizontally" << endl;
                    sum += dfs(pizza, k-1, x, j)%mod;
                }
            }
            
            //vertical cuts
            for(int x = j+1; x < pizza[0].length(); x++){
                if(appRem[i][j] - appRem[i][x] > 0){
                    // cout << i << " " << j <<  "cutting vertically" << endl;
                    sum += dfs(pizza, k-1, i, x)%mod;
                }
            }
            
            return dp[i][j][k] = sum%mod;
        }
    }
};