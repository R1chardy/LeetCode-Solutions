class Solution {
public:
    bool canCross(vector<int>& stones) {
        bool dp[stones.size()][stones.size()];
        memset(dp, false, sizeof(dp));
        dp[0][1] = true;
        int diff;
        for(int i = 1; i < stones.size(); i++){
            for(int j = 0; j < i; j++){
                diff = stones[i] - stones[j];
                if(diff >= 0 && diff < stones.size() && dp[j][diff]){
                    dp[i][diff] = true;
                    if(diff > 1){
                        dp[i][diff-1] = true;
                    }
                    if(diff < stones.size() - 1){
                        dp[i][diff+1] = true;
                    }
                    if(i == stones.size() - 1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};