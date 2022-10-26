class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0){
            return 0;
        }
        stack<int> valid;
        int count = 0, maxL = INT_MIN, curr = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                valid.push(i);
            }
            else{
                if(valid.empty()){
                    valid.push(i);
                }
                else{
                    if(s[valid.top()] == ')'){
                        valid.push(i);
                    }
                    else{
                        valid.pop();
                        if(valid.empty()){
                            curr = i+1;
                        }
                        else{
                            curr = i-valid.top();
                        }
                    }
                    
                }
            }
            maxL = max(maxL, curr);
        }
        return maxL;
    }
};