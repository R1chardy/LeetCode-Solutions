class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1){
            return s.length();
        }
        unordered_set<char> has;
        int l = 0, r = 0;
        has.emplace(s[l]);
        int maxL = 1;
        while(r < s.length()-1){
            r++;
            if(has.count(s[r]) != 0){
                while(s[l] != s[r]){
                    has.erase(s[l]);
                    l++;
                }
                l++;
            }
            has.emplace(s[r]);
            maxL = max(maxL, r - l + 1);
        }
        return maxL;
    }
};