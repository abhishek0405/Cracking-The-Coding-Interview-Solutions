//https://www.codingninjas.com/codestudio/problems/find-number-of-islands_630512?topList=cracking-the-coding-interview-questions
void dfs(int i,int j,int** arr,int visited[][1001],int n,int m){
    //base cases
    if(i<0 || j<0 || i>=n || j>=m){
        return;
    }
    
    if(visited[i][j]==1){
        return;
    }
    
    visited[i][j] = 1;
    
    if(arr[i][j]==0){
        return;
    }
    
    
    
    for(int t1=-1;t1<=1;t1++){
        for(int t2=-1;t2<=1;t2++){
            if(t1!=0 || t2!=0){
                
                dfs(i+t1,j+t2,arr,visited,n,m);
            
            }
        }
    }
    
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
    int visited[n][1001];
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            visited[i][j] = 0;
        }
    }
    
    int islands = 0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(arr[i][j]==1 && visited[i][j]==0){
                dfs(i,j,arr,visited,n,m);
                islands++;
               // cout<<i<<j<<endl;
            }
        }
    }
    
    return islands;
    
    
}
