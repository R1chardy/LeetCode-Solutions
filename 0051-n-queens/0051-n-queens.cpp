class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    vector<int> queens;

    // Recursively place queens on the board
    backtrack(solutions, board, queens, n);

    return solutions;
}

void backtrack(vector<vector<string>>& solutions, vector<string>& board, vector<int>& queens, int n)
{
    // If we have placed all queens, add the current board configuration to the list of solutions
    if (queens.size() == n)
    {
        solutions.push_back(board);
        return;
    }

    // Try placing a queen on each empty space
    for (int i = 0; i < n; i++)
    {
        // Check if the current position is a valid location for a queen
        if (isValid(board, queens, i))
        {
            // Place the queen on the board
            board[queens.size()][i] = 'Q';
            queens.push_back(i);

            // Recursively place queens on the remaining empty spaces
            backtrack(solutions, board, queens, n);

            // Backtrack and remove the queen from the board
            queens.pop_back();
            board[queens.size()][i] = '.';
        }
    }
}

bool isValid(vector<string>& board, vector<int>& queens, int col)
{
    int row = queens.size();

    // Check if the queen is in the same column as any of the previously placed queens
    for (int i = 0; i < row; i++)
    {
        if (queens[i] == col)
        {
            return false;
        }
    }

    // Check if the queen is in the same diagonal as any of the previously placed queens
    for (int i = 0; i < row; i++)
    {
        int diff = abs(queens[i] - col);
        if (diff == row - i)
        {
            return false;
        }
    }

    return true;
}

};