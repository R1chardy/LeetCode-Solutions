class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
        vector<string> board(n, "");
        string row = "";
        for(int j = 0; j < n; j++){
            row += ".";
        }
        for(int i = 0; i < n; i++){
            board[i] = row;
        }
        for(int i = 0; i< n; i++){
            board[0][i] = 'Q';
            findSolution(board, 0, ret);
            board[0][i] = '.';
        }
        return ret;
    }
    
    void findSolution(vector<string>& board, int i, int& ret, int need = -1){
        need = need == -1? board.size() - 1 : need;
        if(need == 0){
            ret++;
            return;
        }
        for(int x = i+1; x < board.size(); x++){
            for(int y = 0; y < board.size(); y++){
                if(isValid(board, x, y)){
                    board[x][y] = 'Q';
                    findSolution(board, x, ret, need - 1);
                    board[x][y] = '.';
                }
            }
        }
    }
    
    bool isValid(vector<string>& board, int i, int j){
        for(int x = 0; x < board.size(); x++){
            if(i+x < board.size() && j+x < board.size() && board[i+x][j+x] == 'Q'){
                return false;
            }
            if(i+x < board.size() && j-x >= 0 && board[i+x][j-x] == 'Q'){
                return false;
            }
            if(i-x >= 0 && j+x < board.size() && board[i-x][j+x] == 'Q'){
                return false;
            }
            if(i-x >= 0 && j-x >= 0 && board[i-x][j-x] == 'Q'){
                return false;
            }
            if(x != j && board[i][x] == 'Q'){
                return false;
            }
            if(x != i && board[x][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
};