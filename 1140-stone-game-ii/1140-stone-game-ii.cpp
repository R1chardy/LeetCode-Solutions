class Solution {
public:
    int dp[2][101][101] = {};
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(piles, 0, 1, 1);
    }
    
    int solve(vector<int>& piles, int i, int M, int ATurn){
        if(i >= piles.size()){
            return 0;
        }
        else if(dp[ATurn][i][M] != -1){
            return dp[ATurn][i][M];
        }
        int maxV = 0;
        int minV = INT_MAX;
        int sum = 0;
        for(int x = 1; x <= 2*M && i+x <= piles.size(); x++){
            sum += piles[i+x-1];
            if(ATurn){
                maxV = max(maxV, sum + solve(piles, i+x, max(x, M), 0));
            }
            else{
                minV = min(minV, solve(piles, i+x, max(x, M), 1));
            }
        }
        return dp[ATurn][i][M] = ATurn? maxV : minV;
    }
};