class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int maxP, count = 0;
        for(int i = 0; i < colors.length() - 1; i++){
            maxP = i;
            while(colors[i] == colors[i+1]){
                if(neededTime[maxP] > neededTime[i+1]){
                    count += neededTime[i+1];
                }
                else{
                    count += neededTime[maxP];
                    maxP = i+1;
                }
                i++;
            }
        }
        return count;
    }
};