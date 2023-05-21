class Solution {
public:
    int dp[101][101];
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        sort(cuts.begin(), cuts.end());
        return solve(0, n, cuts, 0, cuts.size());
    }
    
    long solve(int leftb, int rightb, vector<int>& cuts, int begI, int endI){
        if(dp[begI][endI] != -1){
            return dp[begI][endI];
        }
        if(begI == endI){
            return 0;
        }
        long minV = INT_MAX;
        for(int i = begI; i < endI; i++){
            minV = min(minV, solve(leftb,cuts[i],cuts,begI,i)+solve(cuts[i],rightb,cuts,i+1,endI));
        }
        return dp[begI][endI] = rightb-leftb+minV;
    }
};