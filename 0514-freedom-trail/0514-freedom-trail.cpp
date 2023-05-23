class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> dp(key.length()+1, vector<int>(ring.length()+1, -1));
        return solve(ring, key, 0, dp);
    }
    
    int solve(string& ring, string& key, int i, vector<vector<int>>& dp){
        if(key.length() == 0){
            return 0;
        }
        else if(dp[key.length()][i] != -1){
            return dp[key.length()][i];
        }
        int mod = 1e9+7;
        int minV = INT_MAX;
        string s = key.substr(1);
        int n = ring.length();
        for(int j = 0; j < ring.length(); j++){
            if(ring[j] == key[0]){
                minV = min(minV, (int)min((i-j+n)%n,(j-i+n)%n) + solve(ring, s, j, dp))%mod;
            }
        }
        return dp[key.length()][i] = (1 + minV)%mod;
    }
};