class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        stringstream ss(s);
        string n;
        while(ss >> n){
            ans.push_back(n);
        }
        string ret;
        for(int i = ans.size()-1; i >= 0; i--){
            if(i != ans.size()-1){
                ret = ret + " ";
            }
            ret = ret + ans[i];
        }
        return ret;
    }
};