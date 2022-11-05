class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag, ran;
        for(auto x : magazine){
            mag[x]++;
        }
        for(auto x : ransomNote){
            ran[x]++;
        }
        for(auto x : ran){
            if(mag[x.first] < x.second){
                return false;
            }
        }
        return true;
    }
};