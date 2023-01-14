class Solution {
public:
    long long numberOfWays(string s) {
        unordered_map<string,long long> mp;
        for(char c : s){
            if(c == '1'){
                mp["101"] += mp["10"];
                mp["01"] += mp["0"];
                mp["1"]++;
            }
            else{
                mp["010"] += mp["01"];
                mp["10"] += mp["1"];
                mp["0"]++;
            }
        }
        return mp["101"] + mp["010"];
    }
};