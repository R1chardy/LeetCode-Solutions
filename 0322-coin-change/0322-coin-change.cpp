class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
    if(amount == 0){
        return 0;
    }

    std::unordered_map<int, int> coins_map{};
    int possible[coins.size()];
    int possibleI = 0;
    int currSmallest = 0;
    int val;

    for(int i = 0; i < coins.size(); i++){
        if(coins[i] > 10000){
            continue;
        }
        coins_map.insert({coins[i], 1});
    }
    for(int i = 1; i <= amount; i++){
        for(int j = 0; j < coins.size(); j++){
            if(i - coins[j] >= 0 && (coins_map.find(i-coins[j]) != coins_map.end())){
                possible[possibleI] = coins_map[i-coins[j]];
                possibleI++;
            }
        }
        if(possibleI == 0){
            continue;
        }
        currSmallest = possible[0];
        for(int k = 0; k < possibleI; k++){
            if (possible[k] < currSmallest){
                currSmallest = possible[k];
            }
        }
        coins_map.insert({i, currSmallest + 1});
        possibleI = 0;
    }
    (coins_map.find(amount) == coins_map.end())? val = -1: val = coins_map.at(amount);
    return val;
    }
};