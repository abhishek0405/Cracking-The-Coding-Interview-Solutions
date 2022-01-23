//https://www.codingninjas.com/codestudio/problems/two-sum_839653?topList=cracking-the-coding-interview-questions
/*

8 -1 3 4 0

8:1
-1:1
3:1


1 -1 -1 2 2

1
-1





*/
#include<unordered_map>
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	// Write your code here. 
    bool flag = false;
    unordered_map<int,int>mp;
    int i,j,curr,complement;
    vector<pair<int,int>>ans;
    for(i=0;i<n;i++){
        curr = arr[i];
        complement = target - curr;
        //present
        if(mp.find(complement)!=mp.end() && mp[complement]>=1){
            ans.push_back(make_pair(curr,complement));
            flag = true;
            mp[complement]--;

        }
        else{
             mp[curr]++;
        }
       
        
    }
    if(flag==false){
        ans.push_back(make_pair(-1,-1));
    }
    
    return ans;
    
    
}
