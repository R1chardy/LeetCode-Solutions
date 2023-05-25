class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto& query : queries){
            int x = 0, y = 0;
            int a = query[0];
            int b = query[1];
            while(a != b){
                if(a > b){
                    a = a/2;
                    x++;
                }
                else{
                    b = b/2;
                    y++;
                }
            }
            ans.push_back(1+x+y);
        }
        return ans;
    }
};