class Solution {
public:
    bool solveSudoku(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    //finding possible
                    bool poss[10];
                    memset(poss, true, 10);
                    for(int x = 0; x < board[0].size(); x++){
                        if(board[i][x] != '.'){
                            poss[board[i][x] - '0'] = false;
                        }
                    }
                    for(int x = 0; x < board.size(); x++){
                        if(board[x][j] != '.'){
                            poss[board[x][j] - '0'] = false;
                        }
                    }
                    for(int x = (i/3)*3; x < (i/3+1)*3; x++){
                        for(int y = (j/3)*3; y < (j/3+1)*3; y++){
                            if(board[x][y] != '.'){
                                poss[board[x][y] - '0'] = false;
                            }
                        }
                    }
                    //false if nothing possible
                    int numT = 0;
                    for(int x = 1; x < 10; x++){
                        if(poss[x]){
                            numT++;
                        }
                    }
                    if(numT == 0){
                        return false;
                    }
                    //backtrack
                    for(int x = 1; x < 10; x++){
                        if(poss[x]){
                            board[i][j] = '0'+x;
                            if(solveSudoku(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    //tried all possible but was not successful
                    return false;
                }
            }
        }
        //reached end of board successfully
        return true;
    }
};