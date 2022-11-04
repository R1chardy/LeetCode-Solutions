class Solution {
public:
    int minimumDistance(string word) {
        vector<vector<vector<int>>> dp(word.length(), vector<vector<int>>(27, vector<int>(27, -1)));
        return solve(word, 0, 26, 26, dp);
    }
    
    int distance(int a, int b){
        if(a == 26){
            return 0;
        }
        return abs(a%6 - b%6) + abs(a/6 - b/6);
    }
    
    int solve(string& word, int i, int l, int r, vector<vector<vector<int>>>& dp){
        if(i == word.size()){
            return 0;
        }
        else if(dp[i][l][r] != -1){
            return dp[i][l][r];
        }
        else{
            return dp[i][l][r] = min(solve(word, i+1, l, word[i]-'A', dp) + distance(r, word[i]-'A'), 
                                    solve(word, i+1, word[i]-'A', r, dp) + distance(l, word[i]-'A'));
        }
    }
};