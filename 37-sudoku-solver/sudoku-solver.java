class Solution {
    public void solveSudoku(char[][] board)
    {
        char[][] newBoard = validSudoku(board, 0);
        
        for (int i = 0; i < 81; i++)
            board[i / 9][i % 9] = newBoard[i / 9][i % 9];
    }

    char[][] validSudoku(char[][] board, int step)
    {
        char[][] resultBoard;
        if (step == 81)
            return board;
        
        if (board[step / 9][step % 9] != '.')
            return validSudoku(boardCopy(board), step + 1);

        TreeSet<Character> validNums = getUnusedNums(board, step);
        if (validNums.isEmpty())
            return null;

        while (!validNums.isEmpty())
        {
            char[][] newBoard = boardCopy(board);
            newBoard[step / 9][step % 9] = validNums.pollFirst();
            if((resultBoard = validSudoku(newBoard, step + 1)) != null)
                return resultBoard;
        }

        return null;
    }

    TreeSet<Character> getUnusedNums(char[][] board, int step)
    {
        TreeSet<Character> unusedNums = new TreeSet<Character>();
        unusedNums.add('1');
        unusedNums.add('2');
        unusedNums.add('3');
        unusedNums.add('4');
        unusedNums.add('5');
        unusedNums.add('6');
        unusedNums.add('7');
        unusedNums.add('8');
        unusedNums.add('9');

        int row = step / 9;
        int column = step % 9;
        int boxRow = row - (row % 3);
        int boxColumn = column - (column % 3);

        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == ('.'))
                continue;

            unusedNums.remove(board[row][i]);
        } 

        for (int i = 0; i < 9; i++)
        {
            if (board[i][column] == ('.'))
                continue;
                
            unusedNums.remove(board[i][column]);
        }
        
        for (int i = 0; i < 9; i++)
        {
            if (board[boxRow + i / 3][boxColumn + i % 3] == ('.'))
                continue;
                
            unusedNums.remove(board[boxRow + i / 3][boxColumn + i % 3]);
        } 

        return unusedNums;
    }

    char[][] boardCopy(char[][] board)
    {
        char[][] newBoard = new char[9][];

        for (int i = 0; i < 9; i++)
        {
            newBoard[i] = Arrays.copyOf(board[i], 9);
        }
        return newBoard;
    }
}