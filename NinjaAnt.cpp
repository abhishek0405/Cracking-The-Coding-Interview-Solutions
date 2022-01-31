//https://www.codingninjas.com/codestudio/problems/ninja-ant_1229380?topList=cracking-the-coding-interview-questions


/*
1 0 1
0 1 0
1 0 1

1 0 1
0 0 0
1 0 1

1 0 1
0 0 0
1 1 1

n e s w
1 2 3 4

*/
vector<int> ninjaAnt(vector<vector<int>> &mat, int sr, int sc, int moves) 
{
	// Write code here.
    int i,j,k,n;
    int currX,currY;
    currX = sr;
    currY = sc;
    n = mat[0].size();
    //dir will be one of n,s,e,w (north south east west)
    char dir = 'e';
    
    for(i=0;i<moves;i++){
        //rot right and move
        if(mat[currX][currY]==1){
            
            mat[currX][currY] = 0;
            
            if(dir=='e'){
                dir='s';
                currX++;
        	}
        
            else if(dir=='s'){
                dir = 'w';
                currY--;
            }

            else if(dir=='w'){
                dir = 'n';
                currX--;
            }

            else if(dir=='n'){
                dir='e';
                currY++;
            }
            
            if(currX<0 || currY<0 || currX>=n || currY>=n){
                return {-1,-1};
            }
            
       }
        
       else{ 
           mat[currX][currY] = 1;
            
            if(dir=='e'){
                dir='n';
                currX--;
        	}
        
            else if(dir=='s'){
                dir = 'e';
                currY++;
            }

            else if(dir=='w'){
                dir = 's';
                currX++;
            }

            else if(dir=='n'){
                dir='w';
                currY--;
            }
            
            if(currX<0 || currY<0 || currX>=n || currY>=n){
                return {-1,-1};
            }
            
       }
     }
     return {currX,currY};
}
