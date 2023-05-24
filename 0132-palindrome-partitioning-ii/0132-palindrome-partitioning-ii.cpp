class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), false));
        for(int i = 0; i < s.length(); i++){
            isPalindrome[i][i] = true;
        }
        for(int i = 1; i < s.length(); i++){
            for(int j = 0; j+i < s.length(); j++){
                if(s[j] == s[j+i] && (i == 1 || isPalindrome[j+1][j+i-1])){
                    isPalindrome[j][j+i] = true;
                }
            }
        }
        vector<int> dp(s.length(), INT_MAX);
        for(int i = 0; i < s.length(); i++){
            if(isPalindrome[0][i]){
                dp[i] = 0;
            }
            else{
                for(int j = 1; j <= i; j++){
                    if(isPalindrome[j][i]){
                        dp[i] = min(dp[i], 1+dp[j-1]);
                    }
                }
            }
        }
        return dp[s.length()-1];
    }
};