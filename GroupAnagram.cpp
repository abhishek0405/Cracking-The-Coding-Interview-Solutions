//https://www.codingninjas.com/codestudio/problems/group-anagrams_800285?topList=cracking-the-coding-interview-questions
/*
eat tea tan ate nat bat
a b c
N*N*K(LogK)


N*N + N*K
*/
#include<algorithm>

vector<vector<int>> getFrequency(vector<string>&inputStr, int n){
    vector<vector<int>> freq;
    
    int i,j;
    for(i=0;i<n;i++){
        string s = inputStr[i];
        vector<int>temp(26,0);
        //loop through string
        for(j=0;j<s.length();j++){
            temp[s[j]-'a']++;
        }
        //append to freq
        freq.push_back(temp);
    }
    
    return freq;
}
bool isAnagram(int i, int j, vector<vector<int>>&freq){
    //check if equal
    for(int t = 0;t<26;t++){
        if(freq[i][t] != freq[j][t]){
            return false;
        }
    }
    return true;
   
}


vector<vector<string>> getGroupedAnagrams(vector<string> &inputStr, int n)
{
    // Write your code here
    
    vector<vector<int>> freq = getFrequency(inputStr,n);
    
    vector<vector<string>>ans;
    vector<bool>visited(n+1,0);
    int i,j;
    for(i=0;i<n;i++){
        //unvisited
        vector<string>temp;
        if(visited[i]==0){
            temp.push_back(inputStr[i]);
            visited[i]=1;
            for(j=i+1;j<n;j++){
            	if(isAnagram(i,j,freq)){
                    temp.push_back(inputStr[j]);
                    visited[j] = 1;
                }
        	}
            ans.push_back(temp);
        }
        
    }
    
    return ans;
}
