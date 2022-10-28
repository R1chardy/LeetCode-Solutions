class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        vector<string> ans;
        vector<pair<string,string>> ana(strs.size());
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            ana[i] = {temp, strs[i]};
        }
        
        sort(ana.begin(), ana.end());
        
        string prev = ana[0].first;
        for(auto x : ana){
            if(x.first == prev){
                ans.push_back(x.second);
            }
            else{
                ret.push_back(ans);
                ans.clear();
                ans.push_back(x.second);
                prev = x.first;
            }
        }
        
        if(!ans.empty()){
            ret.push_back(ans);
        }
        
        return ret;
    }
};