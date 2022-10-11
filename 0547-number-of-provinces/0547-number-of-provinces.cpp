class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> provinces = isConnected;
        int count = 0;
        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j < isConnected[0].size(); j++){
                if(provinces[i][j]){
                    dfs(provinces, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& provinces, int i, int j){
        provinces[i][j] = 0;
        for(int k = 0; k < provinces[0].size(); k++){
            if(provinces[j][k]){
                dfs(provinces, j, k);
            }
        }
    }
};