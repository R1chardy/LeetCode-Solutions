class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> chars;
        for(auto x : s){
            chars[x]++;
        }
        int sum = 0;
        bool hasOdd = false;
        for(auto x : chars){
            if(x.second % 2 == 1){
                hasOdd = true;
                sum += x.second-1;
            }
            else{
                sum += x.second;
            }
        }
        if(hasOdd){
            sum += 1;
        }
        return sum;
    }
};