class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int start = 0;
        int end = 0;
        int currLongest = 0;
        std::string longest;
        for(int i = 0; i < s.length(); i++){
            start = i;
            end = i;
            while (end < s.length() - 1 && s.at(end+1) == s.at(end)) {
                end++;
            }
        while(start > 0 && end < s.length() - 1 && (s.at(start - 1) == s.at(end + 1))){
                end++;
                start--;
            }
            if ((end - start + 1) > currLongest){
                longest = s.substr(start, end - start + 1);
                currLongest = end - start + 1;
            }
        }
        return longest;
    }
};