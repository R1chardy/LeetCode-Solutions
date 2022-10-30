class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rc = 0;
        int cc = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    if(i == 0 || j == 0){
                        if(i == 0){
                            rc = 1;
                        }
                        if(j == 0){
                            cc = 1;
                        }
                    }
                    else{
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(rc){
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[0][j] = 0;
            }
        }
        if(cc){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }
    }
};