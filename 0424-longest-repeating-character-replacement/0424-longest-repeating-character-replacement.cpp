class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<char> chars;
        for(int i = 0; i < s.length(); i++){
            if(find(chars.begin(), chars.end(), s[i]) == chars.end()){
                chars.push_back(s[i]);
            }
        }
        
        int leftW = 0;
        int rightW = 0;
        int extra = 0;
        char target;
        int maxLen = 0;
        for(int i = 0; i < chars.size(); i++){
            leftW = 0;
            rightW = 0;
            extra = 0;
            target = chars[i];
            while(leftW <= s.length() - 1){
                while((s[rightW] == target || extra < k) && rightW < s.length()){
                    if(s[rightW] != target){
                        extra++;
                    }
                    rightW++;
                }
                maxLen = max(maxLen, rightW - leftW);
                while((s[leftW] == target) && leftW < s.length()){
                    leftW++;
                }
                extra--;
                leftW++;
            }
        }
        return maxLen;
    }
};