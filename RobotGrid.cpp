//https://www.codingninjas.com/codestudio/problems/robot-grid_1229491?topList=cracking-the-coding-interview-questions
/*

[0 0 0 0]
[1 1 1 1]
[0 1 1 0]

0  0.  0. 0. 0
0  1   1  1  1
0 -1  -1  1  2
0  0  -1 -1  2


0 0
0 1

*/
#include<algorithm>
void solve(vector<vector<int>>&grid, vector<vector<vector<int>>>&paths, int row, int col, int n, int m,vector<vector<int>>&path){
    //base cases
   
    if(row>=n || col>=m){
        return;
    }
    
    
    if(grid[row][col]==1){
        return;
    } 
    
    if(row ==n-1 && col == m-1){
        //add final coordinate
        path.push_back({row,col});
        paths.push_back(path);
        path.pop_back();
        return;
    }
    
    //go right
    path.push_back({row,col});
    solve(grid,paths,row,col+1,n,m,path);
    
    //go down
    solve(grid,paths,row+1,col,n,m,path);
    if(path.size()>0){
         path.pop_back();
    }
   
}


vector<vector<int>> findPath(vector<vector<int>> &grid) {
	// Write your code here.
    int row,col,n,m;
    n = grid.size();
    m = grid[0].size();
    row = col = 0;
    vector<vector<int>>path;
    vector<vector<int>>dp;
    
    if(grid[n-1][m-1]==1){
        return {{-1,-1}};
    }
    
    //fill 
    for(row=0;row<=n;row++){
        vector<int>temp;
        for(col = 0;col<=m;col++){
          	temp.push_back(0);
        }
        dp.push_back(temp);
    }
    //dp[i][j] stores if end is reachable from given cell
    for(row=n;row>=1;row--){
        for(col=m;col>=1;col--){
            //end reachable
            if(row==n && col==m){
                dp[row][col] = 1;
            }
            else{
                
            
          	if(grid[row-1][col-1]==1){
                //cannot reach from here
                dp[row][col] = 0;
            }
            else{
                dp[row][col] = 0;
                //go right
                if(col+1<=m){
                    //can reach right cell
                    //right cell is row, col+1
                    //but for grid it is row-1,col since 0 index
                    if(grid[row-1][col]==0){
                        //can reach from right cell
                        if(dp[row][col+1]==1){
                            dp[row][col]=1;
                        }
                    }
                }
                
                //go down
                if(row+1<=n){
                    //can reach down
                    if(grid[row][col-1]==0){
                        if(dp[row+1][col]==1){
                            dp[row][col] = 1;
                        }
                    }
                }
            }
                
            }
        }
     }
    
    //cout<<dp[n][m]<<endl;
    //unreachable
     if(dp[1][1]==0){
        return {{-1,-1}};
    }
    
    bool flag = false;
    //since going through dp array
    row = col = 1;
    
    while(true){
        //path exists
        path.push_back({row-1,col-1});
        int newRow = n+1;
        int newCol = m+1;
        //going down
        if(row+1<=n && dp[row+1][col]==1){
            newRow = row+1;
            newCol = col;
        }
        //if going right also possible,then 
        //do this as lexographicallty smaller
        if(col+1<=m && dp[row][col+1]==1){
            newRow = row;
            newCol = col+1;
        }
        
        if(newRow == n+1 || newCol ==m+1){
              break;
        }
        
        if(newRow == n && newCol == m && dp[newRow][newCol]==1){
            path.push_back({n-1,m-1});
            break;
        }
        
        
        
        row = newRow;
        col = newCol;
        
        
    }
   
    return path;
    
    
  

        
}
