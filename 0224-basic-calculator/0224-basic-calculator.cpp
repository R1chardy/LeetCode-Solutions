class Solution {
public:
    int calculate(string s) {
        uint sign = 1, num = 0, ans = 0;
        stack<tuple<uint,uint,uint>> st;
        for(char c : s){
            if(isdigit(c)){
                num = num*10 + c-'0';
            }
            else{
                ans += num*sign;
                num = 0;
            }
            if(c == '-'){
                sign = -1;
            }
            else if(c == '+'){
                sign = 1;
            }
            else if (c == '('){
                st.push(make_tuple(sign,num,ans));
                sign = 1, num = 0, ans = 0;
            }
            else if(c == ')'){
                int in = ans;
                tie(sign,num,ans) = st.top();
                st.pop();
                ans += in*sign;
            }
        }
        ans += num*sign;
        return ans;
    }
};