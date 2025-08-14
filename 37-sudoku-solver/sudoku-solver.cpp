class Solution {
public:
bool issafe( vector<vector<char>>& board , int row , int col , int temp)
{
    temp = temp+'0';
    for ( int i = 0 ; i < 9 ; i++ )
    {
        if ( board[row][i] == temp)
        return false;
        if ( board[i][col] == temp)
        return false;
    }
    int rowstart = (row /3 )*3;
    int colstart = (col/3)*3;
    for ( int j = rowstart ; j < rowstart +3 ; j++)
    {
        for ( int k = colstart ; k < colstart+3 ; k++)
        {
             if ( board [j][k] == temp)
             return false;
        }
    }
    return true;
}

bool helper (vector<vector<char>>& board , int row , int col )
 {
    //base cases as we should use recursion to check every element possible for every entry
    if ( row == 9)
    return true;
    int nextrow = row ;
    int nextcol = col+1;
    if ( nextcol == 9 )
    {
        nextrow = row+1;
        nextcol = 0;
    }
    if ( board[row][col] != '.')
    {
        return helper ( board ,nextrow , nextcol );

    }
    for ( int i =1 ; i <= 9  ; i++)
    {
        
        if ( issafe( board , row , col , i)  )
        {
            board[row][col] = i + '0';
            if ( helper ( board , nextrow , nextcol))
            return true;
            board[row ][col] = '.';
        }
        
    }
    return false;


 }
    void solveSudoku(vector<vector<char>>& board) {
        helper ( board , 0 , 0 );
    }
};