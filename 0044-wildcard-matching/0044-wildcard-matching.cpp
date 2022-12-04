class Solution {
public:
    bool isMatch(string s, string p)
{
    int m = s.length();
    int n = p.length();

    // Create a two-dimensional boolean array to store the results
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Initialize the first row and column to true
    dp[0][0] = true;
    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = false;
    }
    for (int j = 1; j <= n; j++)
    {
        dp[0][j] = p[j - 1] == '*' && dp[0][j - 1];
    }

    // Fill in the array using the rules described above
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    // Return the result
    return dp[m][n];
}

};