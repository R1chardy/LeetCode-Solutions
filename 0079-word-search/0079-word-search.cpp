class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(hasSol(board, word, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool hasSol(vector<vector<char>>& board, string word, int i = 0, int j = 0, int k = 0){
        if(board[i][j] == word[k] && k == word.size()-1){
            return true;
        }
        if(board[i][j] != word[k]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '.';
        bool ret = false;
        if(i < board.size()-1){
            ret = ret || hasSol(board, word, i+1, j, k+1);
        }
        if(i > 0){
            ret = ret || hasSol(board, word, i-1, j, k+1);
        }
        if(j < board[0].size()-1){
            ret = ret || hasSol(board, word, i, j+1, k+1);
        }
        if(j > 0){
            ret = ret || hasSol(board, word, i, j-1, k+1);
        }
        board[i][j] = temp;
        return ret;
    }
};