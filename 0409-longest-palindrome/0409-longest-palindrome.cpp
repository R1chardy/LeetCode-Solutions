class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto& c : s){
            mp[c]++;
        }
        int sum = 0, mid = 0;
        for(auto& pair : mp){
            if(pair.second%2){
                mid = 1;
                sum += pair.second-1;
            }
            else{
                sum += pair.second;
            }
        }
        return sum + mid;
    }
};