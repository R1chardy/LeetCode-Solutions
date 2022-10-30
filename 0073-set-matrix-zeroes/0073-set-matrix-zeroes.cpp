class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rowV(matrix.size(), 1);
        vector<int> colV(matrix[0].size(), 1);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rowV[i] = 0;
                    colV[j] = 0;
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(!(rowV[i] && colV[j])){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};