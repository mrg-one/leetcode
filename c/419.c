
static inline int hasRight(char** board, int i, int j, int colSize)
{
    return j + 1 < colSize && board[i][j + 1] == 'X';
}
static inline int hasDown(char** board, int i, int j, int rowSize)
{
    return i + 1 < rowSize && board[i + 1][j] == 'X';
}

int countBattleships(char** board, int boardSize, int* boardColSize) {

    int count = 0;

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[i]; j++)
        {
            if (board[i][j] == 'X' && !hasRight(board, i, j, boardColSize[i]) && !hasDown(board, i, j, boardSize))
            {
                count++;
            }
        }
    }
    

    return count;
}