class Solution {
public:
    int dp[1001][1001];
    string shortestCommonSupersequence(string str1, string str2) {
        fill(&dp[0][0], &dp[1000][1000], INT_MAX);
        helper(str1, str2, 0, 0);
        int i = 0, j = 0;
        string ans = "";
        while(i < str1.length() && j < str2.length()){
            if(str1[i] == str2[j]){
                ans = ans + str1[i];
                i++;
                j++;
            }
            else{
                if(dp[i][j+1] < dp[i+1][j]){
                    ans = ans + str2[j];
                    j++;
                }
                else{
                    ans = ans + str1[i];
                    i++;
                }
            }
        }
        while(i < str1.length()){
            ans = ans + str1[i];
            i++;
        }
        while(j < str2.length()){
            ans = ans + str2[j];
            j++;
        }
        return ans;
    }
    
    int helper(string& str1, string& str2, int i, int j){
        if(i >= str1.length() && j >= str2.length()){
            return dp[i][j] = 0;
        }
        else if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        else if(i >= str1.length()){
            return dp[i][j] = min(dp[i][j], static_cast<int>(str2.length())-j);
        }
        else if(j >= str2.length()){
            return dp[i][j] = min(dp[i][j], static_cast<int>(str1.length())-i);
        }
        else{
            if(str1[i] == str2[j]){
                return dp[i][j] = 1 + helper(str1, str2, i+1, j+1);
            }
            else{
                int s1 = 1 + helper(str1, str2, i+1, j);
                int s2 = 1 + helper(str1, str2, i, j+1);
                return dp[i][j] = min(s1, s2);
            }
        }
    }
};