class Solution {
public:
    int dp[101][201] = {};
    int countRoutes(vector<int>& locations, int start, int finish, int fuel, bool first = true) {
        int sum = 0;
        int mod = 1e9+7;
        if(first){
            for(int i = 0; i < 101; i++){
                for(int j = 0; j < 201; j++){
                    dp[i][j] = -1;
                }
            }
        }
        if(start == finish){
            sum += 1;
        }
        if(dp[start][fuel] != -1){
            return dp[start][fuel];
        }
        for(int i = 0; i < locations.size(); i++){
            if(i != start && abs(locations[i] - locations[start]) <= fuel){
                sum += countRoutes(locations, i, finish, 
                                   fuel - abs(locations[i] - locations[start]), false) % mod;
                sum %= mod;
            }
        }
        return dp[start][fuel] = sum;
    }
};