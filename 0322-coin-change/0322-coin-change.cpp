class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        map<int,int> mp;
        return solve(mp, coins, amount);
    }
    
    int solve(map<int,int>& mp, vector<int>& coins, int amount){
        if(amount < 0){
            return -1;
        }
        else if(amount == 0){
            return 0;
        }
        else if(count(coins.begin(), coins.end(), amount)){
            return 1;
        }
        else if(mp[amount] != 0){
            return mp[amount];
        }
        else{
            int minV = INT_MAX;
            for(auto& coin : coins){
                int ans = solve(mp, coins, amount-coin);
                if(ans != -1){
                    minV = min(minV, 1 + ans);
                }
            }
            return mp[amount] = minV == INT_MAX? -1 : minV;
        }
    }
};