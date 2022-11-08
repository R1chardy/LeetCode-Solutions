class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        long temp;
        for(auto x : tokens){
            if(x == "+"){
                temp = s.top();
                s.pop();
                temp += s.top();
                s.pop();
                s.push(temp);
            }
            else if(x == "-"){
                temp = s.top();
                s.pop();
                temp = s.top() - temp;
                s.pop();
                s.push(temp);
            }
            else if(x == "/"){
                temp = s.top();
                s.pop();
                temp = s.top() / temp;
                s.pop();
                s.push(temp);
            }
            else if(x == "*"){
                temp = s.top();
                s.pop();
                temp *= s.top();
                s.pop();
                s.push(temp);
            }
            else{
                s.push(stoi(x));
            }
        }
        return s.top();
    }
};