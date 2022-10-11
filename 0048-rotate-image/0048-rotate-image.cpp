class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //flipping
        int temp;
        for(int i = 0; i < matrix.size() / 2; i++){
            for(int j = 0; j < matrix[0].size(); j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[matrix.size() - i - 1][j];
                matrix[matrix.size() - i - 1][j] = temp;
            }
        }
        //mirroring
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i + 1; j < matrix[0].size(); j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};