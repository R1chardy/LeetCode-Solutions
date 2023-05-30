class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        stringstream ss(s);
        string n;
        while(ss >> n){
            ans.push_back(n);
        }
        reverse(ans.begin(), ans.end());
        string ret;
        for(int i = 0; i < ans.size(); i++){
            if(i != 0){
                ret = ret + " ";
            }
            ret = ret + ans[i];
        }
        return ret;
    }
};