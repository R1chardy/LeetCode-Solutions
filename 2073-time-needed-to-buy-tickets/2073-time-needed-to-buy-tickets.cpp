class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sum = 0;
        for(int i = 0; i < tickets.size(); i++){
            if(tickets[i] >= tickets[k]){
                sum += tickets[k];
            }
            else{
                sum += tickets[i];
            }
            if(i > k && tickets[i] >= tickets[k]){
                sum--;
            }
        }
        return sum;
    }
};