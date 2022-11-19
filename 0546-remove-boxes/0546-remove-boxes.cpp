class Solution {
public:
    int dp[101][101][101];
    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));
        return solve(boxes, 0, boxes.size()-1, 0);
    }
    
    int solve(vector<int>& boxes, int l, int r, int k){
        if(l == r){
            return (k+1)*(k+1);
        }
        else if(l > r){
            return 0;
        }
        else if(dp[l][r][k] != -1){
            return dp[l][r][k];
        }
        int maxV = (k+1)*(k+1) + solve(boxes, l+1, r, 0);
        for(int i = l+1; i <= r; i++){
            if(boxes[i] == boxes[l]){
                maxV = max(maxV, solve(boxes, l+1, i-1, 0) + solve(boxes, i, r, k+1));
            }
        }
        return dp[l][r][k] = maxV;
    }
};