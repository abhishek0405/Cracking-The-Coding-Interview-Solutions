//https://www.codingninjas.com/codestudio/problems/equal-number-of-boys-and-girls_1229397?topList=cracking-the-coding-interview-questions
/*
GGGBGBBBBG

0 -1 -2 -3 -2 -3 -2 -1 0 1 0
0 1   2. 3. 4. 5  6. 7 8 9 10

0: 0,8,10
-1: 1,7
-2 : 2,4,6
-3: 3,5
1:9


1 1 1 -1 1 -1 1
0 1 2 3 2 3 2 3

0 -1 0


n

-n    n

2*n +1 
*/
#include<unordered_map>
int lengthOfLongestSubArr(string &s)
{
    //  Write your code here.
    
    unordered_map<int,pair<int,int>>mp;
    int i,j,n;
    int currSum = 0;
    mp[currSum].first = 0;
    mp[currSum].second = 0;
    n = s.length();
    //stores 
    vector<int>firstIndex(2*n+1,-1);
    vector<int>lastIndex(2*n+1,-1);
    firstIndex[currSum+n] = 0;
    
    for(i=0;i<n;i++){
        
        if(s[i]=='G'){
            currSum--;
        }
        else if(s[i]=='B'){
            currSum++;
        }
        //added due to bad test case in question
        else{
            continue;
        }
 
//         if(mp.find(currSum)==mp.end()){
//             mp[currSum].first = i+1;
//             mp[currSum].second = i+1;
//         }
//         else{
//             mp[currSum].first = min(mp[currSum].first,i+1);
//             mp[currSum].second = max(mp[currSum].second,i+1);
//         }
        
        if(firstIndex[currSum+n] == -1){
            firstIndex[currSum+n] = i+1;
            
        }
        else{
            lastIndex[currSum+n] = i+1;
        }
        
    }
    int ans = 0;
    for(i=0;i<2*n+1;i++){
        if(firstIndex[i]!=-1){
             ans = max(ans,lastIndex[i] - firstIndex[i]);
        }
       
    }
    
    return ans;
    
}
