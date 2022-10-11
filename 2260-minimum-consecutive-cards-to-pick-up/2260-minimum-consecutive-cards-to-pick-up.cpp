class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> seen;
        int minC = INT_MAX;
        for(int i = 0; i < cards.size(); i++){
            if(seen.find(cards[i]) == seen.end()){
                seen[cards[i]] = i;
            }
            else{
                minC = min(minC, i - seen[cards[i]]);
                seen[cards[i]] = i;
            }
        }
        return minC == INT_MAX? -1 : minC + 1;
    }
};