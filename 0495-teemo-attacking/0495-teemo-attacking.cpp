class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int l = timeSeries[0];
        int sum = 0;
        for(int& i : timeSeries){
            if(i-l >= duration){
                sum += duration;
            }
            else{
                sum += i-l;
            }
            l = i;
        }
        sum += duration;
        return sum;
    }
};