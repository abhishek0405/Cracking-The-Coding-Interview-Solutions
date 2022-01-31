
//https://www.codingninjas.com/codestudio/problems/word-distance_1229393?topList=cracking-the-coding-interview-questions
/*
 a b d a c c a g c
 0 1 2 3 4 5 6 7 8
 
 a: 0, 3, 6
 c: 4, 5, 8
 
*/
#include<unordered_map>
int getDistance(string s1,string s2, unordered_map<string,vector<int>>&mp,int n){
     if(mp.find(s1)==mp.end() || mp.find(s2)==mp.end()){
         return n;
     }
     vector<int>v1 = mp[s1];
     vector<int>v2 = mp[s2];
    //int minDist = 0;
     int minDist = abs(v1[0] - v2[0]);
     int i,j;
     i=j=0;
     while(i<v1.size() && j<v2.size()){
        minDist = min(minDist,abs(v1[i] - v2[j]));
        if(v1[i]>v2[j]){
            j++;
        }
        else{
            i++;
        }
     }
    
    return minDist;
}
vector<int> wordDistance(int n, int q, vector<string>& arr, vector<vector<string>>& queries){
    // Write your code here.
    unordered_map<string,vector<int>> mp;
    
    int i,j,k;
    int distance;
    for(i=0;i<n;i++){
        string word = arr[i];
        mp[word].push_back(i);
    }
    vector<int>ans;
    
    for(i=0;i<q;i++){
        string s1 = queries[i][0];
        string s2 = queries[i][1];
        
        //get distance
        distance = getDistance(s1,s2,mp,n);
        //distance=0;
        ans.push_back(distance);
    }
    
    return ans;
    
}
