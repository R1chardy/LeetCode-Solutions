class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
{
    backtrack(board);
}

bool backtrack(vector<vector<char>>& board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // If the current cell is empty, try filling it with a digit
            if (board[i][j] == '.')
            {
                // Try filling the cell with each of the digits 1-9
                for (int d = 1; d <= 9; d++)
                {
                    // Check if the current digit is valid for the current cell
                    if (isValid(board, i, j, d))
                    {
                        // Fill the cell with the current digit
                        board[i][j] = '0' + d;

                        // Recursively fill the remaining empty cells
                        if (backtrack(board))
                        {
                            return true;
                        }

                        // If the current digit does not lead to a solution, backtrack and try a different digit
                        board[i][j] = '.';
                    }
                }

                // If no digit is valid for the current cell, return false to backtrack
                return false;
            }
        }
    }

    // If all cells are filled, return true to indicate that a solution is found
    return true;
}

bool isValid(vector<vector<char>>& board, int row, int col, int d)
{
    // Check if the current digit is already present in the current row
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] - '0' == d)
        {
            return false;
        }
    }

    // Check if the current digit is already present in the current column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] - '0' == d)
        {
            return false;
        }
    }

    // Check if the current digit is already present in the current 3x3 sub-box
    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;
    for (int i = rowStart; i < rowStart + 3; i++)
    {
        for (int j = colStart; j < colStart + 3; j++)
        {
            if (board[i][j] - '0' == d)
            {
                return false;
            }
        }
    }

    return true;
}

};