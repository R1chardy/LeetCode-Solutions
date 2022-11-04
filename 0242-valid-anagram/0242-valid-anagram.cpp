class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        map<char, int> s1, s2;
        for(auto x : s){
            s1[x]++;
        }
        for(auto x : t){
            s2[x]++;
        }
        for(auto x : s1){
            if(x.second != s2[x.first]){
                return false;
            }
        }
        return true;
    }
};