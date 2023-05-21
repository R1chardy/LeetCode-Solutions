class Solution {
public:
    int numberOfWays(string corridor) {
        int prevI = 0, counter = 0, mod = 1e9+7;
        long ans = 1;
        for(int i = 0; i < corridor.length(); i++){
            if(corridor[i] == 'S'){
                counter++;
                if(counter > 2 && counter%2){
                    ans = (ans*(i - prevI))%mod;
                }
                prevI = i;
            }
        }
        return counter%2 || counter < 2? 0 : ans;
    }
};