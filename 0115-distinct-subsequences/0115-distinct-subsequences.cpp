class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint>> dp(s.length()+1, vector<uint>(t.length()+1, 0));
        for(int i = 0; i <= s.length(); i++){
            dp[i][t.length()] = 1;
        }
        for(int i = s.length()-1; i >= 0; i--){
            for(int j = t.length()-1; j >= 0; j--){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i+1][j] + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};