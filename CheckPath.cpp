//https://www.codingninjas.com/codestudio/problems/path-between-two-vertices-in-a-directed-graph_920534?topList=cracking-the-coding-interview-questions
#include<queue>
#include<list>
#include<map>
bool checkPathExists(int v, int e, int source, int destination, vector<vector<int>> &edges) 
{
    // Write your code here
    
    map<int,list<int>> mp;
    int i,j,from,to;
    
    for(i=0;i<e;i++){
        from = edges[i][0];
        to = edges[i][1];
        mp[from].push_back(to);
    }
    
    queue<int> q;
    vector<int>visited(v,0);
    
    q.push(source);
    visited[source]=1;
    
    while(!q.empty()){
        int curr = 	q.front();
        if(curr==destination){
            return true;
        }
        q.pop();
        for(auto &nbr: mp[curr]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = 1;
            }
        }
    }
    
    return false;
    
    
    
    
    
}
