class Solution {
public:
    int countHomogenous(string s) {
        long count = 0, continuous = 1;
        char prev = s[0];
        for(int i = 1; i < s.length(); i++){
            if(s[i] == prev){
                continuous++;
            }
            else{
                count += continuous * (continuous + 1) / 2;
                count %= 1000000007;
                continuous = 1;
                prev = s[i];
            }
        }
        count += continuous * (continuous + 1) / 2;
        count %= 1000000007;
        return (int)count;
    }
};