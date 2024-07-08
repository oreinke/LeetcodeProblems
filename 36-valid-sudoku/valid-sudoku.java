class Solution {
    public boolean isValidSudoku(char[][] board)
    {
        return preliminarySudokuCheck(board);

    }

    boolean preliminarySudokuCheck(char[][] board)
    {
        HashSet<Character> usedNums;

        // check rows
        for (int i = 0; i < 9; i++)
        {
            usedNums = new HashSet<Character>();
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    char curChar = board[i][j];
                    if (usedNums.contains(curChar))
                        return false;
                    usedNums.add(curChar);
                }
            }
        }
        
        // check columns
        for (int i = 0; i < 9; i++)
        {
            usedNums = new HashSet<Character>();
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    char curChar = board[j][i];
                    if (usedNums.contains(curChar))
                        return false;
                    usedNums.add(curChar);
                }
            }
        }

        // check boxes 
        for (int i = 0; i < 9; i++)
        {
            int boxRow = (i / 3) * 3;
            int boxColumn = (i % 3) * 3;
            usedNums = new HashSet<Character>();
            for (int j = 0; j < 9; j++)
            {
                if (board[boxRow + j / 3][boxColumn + j % 3] != '.')
                {
                    char curChar = board[boxRow + j / 3][boxColumn + j % 3];
                    if (usedNums.contains(curChar))
                        return false;
                    usedNums.add(curChar);
                }
            }
        }
        return true;
    }

}
