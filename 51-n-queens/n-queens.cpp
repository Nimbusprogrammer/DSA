class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n , string(n,'.'));
        vector<vector<string>> ans;
        //logic is going recursively through rows and forming a for loop to cover coloumns in each rows .
        int row = 0;
        nqueens(board , ans , row , n);
        return ans;
    }
    void nqueens ( vector<string>& board,vector<vector<string>>& ans ,int row , int n )
    {
        if ( row == n)
        {
            ans.push_back(board);
            return;
        }
       for ( int i = 0 ; i < n ; i++)
       {
              if ( issafe(row ,i,n , board))
              {
                board[row][i] ='Q';
                nqueens(board , ans , row+1 , n);
                board[row][i] ='.';
              }
       }
        
    }
     bool issafe ( int row , int  col , int n  , vector<string> &board)
     {
        //for safety check its both diagonal , vertical up coloumn  
        for ( int i = row ; i >= 0; i--)
        {
            if ( board [i][col] == 'Q')
            return false ;
        }
        //checking both diagonals : int i = 10 , j = 5 , k = -1 --> this kind of ***declaration with initilization*** is correct .
        for ( int i = row , j = col ; i >= 0 && j >= 0 ; i--, j--)
        {
             if ( board [i][j] == 'Q')
            return false ;
        }
         for ( int i = row , j = col ; i >= 0 && j < n; i--, j++)
        {
             if ( board [i][j] == 'Q')
            return false ;
        }
        return true;

     }
};