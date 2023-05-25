class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto& query : queries){
            vector<int> path1 = solve(query[0]);
            vector<int> path2 = solve(query[1]);
            while(!path1.empty() && !path2.empty() && path1.back() == path2.back()){
                path1.pop_back();
                path2.pop_back();
            }
            ans.push_back(path1.size() + path2.size() + 1);
            
        }
        return ans;
    }
    
    vector<int> solve(int n){
        vector<int> ret;
        while(n != 1){
            ret.push_back(n);
            if(n%2){
                n = (n-1)/2;
            }
            else{
                n = n/2;
            }
        }
        ret.push_back(1);
        return ret;
    }
};