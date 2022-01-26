/*
    Time Complexity : O(N)
    Space Complexity : O(M)

    where, N denotes the size of array 'moves' and 'M' = 3
*/

string ticTacToeWinner(vector<vector<int>> moves, int n) 
{   
    // Minimum of 5 moves are required to decide a winner
    if (n <= 4) 
    {  
        return "uncertain";  
    }

    vector<int> rowSum(3, 0), colSum(3, 0), diagSum(2, 0);
    int curMove, row, col;

    for (int i = 0; i < n; i++) 
    {
        row = moves[i][0], col = moves[i][1];
        curMove = 1;
        if (i & 1) curMove = 4;

        rowSum[row] += curMove;
        colSum[col] += curMove;
       
        // Sum for diagonal from top-left to bottom-right
        if (row == col)  
        {
            diagSum[0] += curMove;
        }    

        // Sum for diagonal from top-right to bottom-left
        if (row == 2 - col)
        {  
            diagSum[1] += curMove;
        }
        
        // Sum equal to 3 means 'player1' won
        if (rowSum[row] == 3 || colSum[col] == 3 || diagSum[0] == 3 || diagSum[1] == 3)
        {  
            return "player1";
        }

        // Sum equal to 12 means 'player2' won
        else if (rowSum[row] == 12 || colSum[col] == 12 || diagSum[0] == 12 || diagSum[1] == 12)  
        {
            return "player2";
        }
    }
    
    // 'draw' - No winner and all grid positions are marked
    if (n == 9) 
    {
        return "draw";  
    }
    
    // 'uncertain' - No winner and some grid positions are unmarked
    return "uncertain";         
}
