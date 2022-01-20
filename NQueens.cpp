//https://www.codingninjas.com/codestudio/problems/n-queens_759332?topList=cracking-the-coding-interview-questions
/*
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0

*/
bool isSafe(int i,int j,vector<vector<int>>&board,int n){
    int row,col;
    row = i;
    col = j;
    
    
    //vertical
    for(int t1 = 0;t1<n;t1++){
        if(board[t1][col]==1){
            return false;
        }
    }
    
    //top left
    while(i>=0 && j>=0){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }
    
    i = row;
    j= col;
    //top right
    
    while(i>=0 && j<n){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j++;
    }
    
  	return true;
    
}
    
bool solve(int i,int j,vector<vector<int>>&board,int n,vector<vector<int>>&ans){
    //base cases
    //solved
    if(i==n){
        vector<int>temp;
        for(int t1=0;t1<n;t1++){
            for(int t2=0;t2<n;t2++){
                temp.push_back(board[t1][t2]);
            }
        }
        ans.push_back(temp);
        
        return false;
    }
    //extreme end reach
    if(j==n){
        return false;
    }
    
    bool isPossible;
    //check is position safe
    
    if(isSafe(i,j,board,n)){
        //queen placed
        board[i][j] = 1;
        isPossible = solve(i+1,0,board,n,ans);
        if(!isPossible){
        	board[i][j] = 0;
           // return solve(i,j+1,board,n,ans);
    	}
        else{
            return true;
        }
    }
    isPossible = solve(i,j+1,board,n,ans);
    return isPossible;
    
    
    
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>>board;
    vector<vector<int>>ans;
    int i,j;
    for(i=0;i<n;i++){
        vector<int>temp;
        for(j =0;j<n;j++){
            temp.push_back(0);
        }
        board.push_back(temp);
    }
    
    solve(0,0,board,n,ans);
    return ans;
}
