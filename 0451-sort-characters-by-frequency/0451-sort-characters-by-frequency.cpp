class Solution {
public:
    string frequencySort(string s) {
        string ret = "";
        vector<pair<char, int>> counts;
        for(auto x : s){
            auto iter = find_if(counts.begin(), counts.end(),[&](const auto a){
                return a.first == x;
            });
            if(iter == counts.end()){
                counts.push_back({x, 1});
            }
            else{
                (*iter).second++;
            }
        }
        sort(counts.begin(), counts.end(), [](auto x, auto y){
            return x.second == y.second? x.first < y.first : x.second > y.second;
        });
        for(auto x : counts){
            for(int i = 0; i < x.second; i++){
                ret += x.first;
            }
        }
        return ret;
    }
};