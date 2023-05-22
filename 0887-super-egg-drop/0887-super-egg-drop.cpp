class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return solve(k, n, dp);
    }
    
    int solve(int k, int n, vector<vector<int>>& dp){
        if(k == 1){
            return n;
        }
        else if(n == 0){
            return 0;
        }
        else if(n == 1){
            return 1;
        }
        else if(dp[k][n] != -1){
            return dp[k][n];
        }
        else{
            int l = 1, r = n, minV = INT_MAX;
            while(l <= r){
                int mid = (l+r)/2;
                int right = solve(k, n-mid, dp);     //egg doesn't break, move up
                int left = solve(k-1, mid-1, dp);  //egg breaks, move down
                if(left < right){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
                minV = min(minV, max(left, right));
            }
            return dp[k][n] = 1 + minV;
        }
    }
};