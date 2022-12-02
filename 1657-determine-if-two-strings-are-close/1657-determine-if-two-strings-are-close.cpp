class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()){
            return false;
        }
        map<char,int> w1, w2;
        for(auto x : word1){
            w1[x]++;
        }
        for(auto x : word2){
            w2[x]++;
        }
        unordered_multiset<int> s;
        unordered_set<char> s2;
        for(auto x : w1){
            s2.emplace(x.first);
        }
        for(auto x : w2){
            if(s2.count(x.first) == 0){
                return false;
            }
        }
        for(auto x : w1){
            s.emplace(x.second);
        }
        for(auto x : w2){
            if(s.count(x.second) == 0){
                return false;
            }
            auto it = s.find(x.second);
            s.erase(it);
        }
        return s.empty();
    }
};