//https://www.codingninjas.com/codestudio/problems/longest-word-made-from-other-words_1229401?topList=cracking-the-coding-interview-questions
#include <unordered_set>
bool compare(string a,string b){
    return a.length()>b.length();
}
vector<string> findLongestWordList(vector<string>& wordList){
// 	// Write your code here
    unordered_set<string> dict;

    for(int i = 0; i < wordList.size(); i++){
     	dict.insert(wordList[i]);
    }
	vector<string>ans;
    int maxLen = -1;
    //sort wordlist based on size
    sort(wordList.begin(),wordList.end(),compare);
	for(string &s:wordList){
        //cout<<s<<endl;
        vector<int> dp(s.length() + 1, 0);
        dp[s.length()] = 1;
        int n = s.length();
        //remove s from the set else always true
        dict.erase(s);
        for(int i = n - 1; i >= 0; i--){
           string word;
           for(int j = i; j < n; j++){
                word+=s[j];
                //word ie s[i:j] exists in dict
                if(dict.find(word) != dict.end()){
                    //possible to make from j+1
                    if(dp[j+1]==1){
                        dp[i] = 1;
                        break;
                    }
                }
            }   
    	}
        //possible for currWord
        
        if(dp[0]==1){
           // cout<<s<<endl;
//             cout<<s.length()<<endl;
//             cout<<maxLen<<endl;
            
            if(maxLen==-1 || maxLen ==s.length()){
                
                //cout<<"IN"<<endl;
                maxLen = s.length();
                ans.push_back(s);
            }
        }
        //insert it back
        
        dict.insert(s);
    }
    sort(ans.begin(),ans.end());
    return ans;
   
}
