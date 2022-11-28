class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(auto x : matches){
            if(mp.count(x[0]) == 0){
                mp[x[0]] = 0;
            }
            mp[x[1]]++;
        }
        vector<int> f;
        vector<int> s;
        for(auto x : mp){
            if(x.second == 0){
                f.push_back(x.first);
            }
            else if(x.second == 1){
                s.push_back(x.first);
            }
        }
        return {f, s};
    }
};