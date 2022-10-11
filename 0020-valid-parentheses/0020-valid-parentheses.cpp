class Solution {
public:
    bool isValid(string s) {
        stack<int> brackets;
        char endBracket;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                brackets.push(s[i]);
            }
            else{
                endBracket = brackets.empty()? 'x' : brackets.top();
                brackets.pop();
                if(endBracket == 'x'){
                    return false;
                }
                else if(s[i] == ')' && endBracket != '('){
                    return false;
                }
                else if(s[i] == ']' && endBracket != '['){
                    return false;
                }
                else if(s[i] == '}' && endBracket != '{'){
                    return false;
                }
            }
        }
        if(!brackets.empty()){
            return false;
        }
        return true;
    }
};