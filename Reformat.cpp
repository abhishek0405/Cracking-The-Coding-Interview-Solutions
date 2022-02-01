/*
    Time Complexity : O( N^2)
    Space Complexity: O( N + M )

    Where N is the size of S, and M is the size of DRR
*/

#include <unordered_set>

long long prime = 31;
long long MOD = 1e9 + 7;

int reFormating(int m, string s, vector<string>& drr){

    // Converting all the strings in DRR to their hash equivalent 
    unordered_set<string> setDrr;

    for(int i = 0; i < m; i++){
     	setDrr.insert(drr[i]);
    }


    vector<int> dp(s.length() + 1, 1e9);

    // Base Case
    dp[s.length()] = -1;
	int n = s.length();
    for(int i =n - 1; i >= 0; i--){
		string word;
    

        
        for(int j = i; j < n; j++){
            word+=s[j];

            if(setDrr.find(word) != setDrr.end()){
                if(dp[j+1]!= 1e9){
                   dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
              
            }
        }   
    }
    int ans = dp[0];
    if(ans == 1e9){
        return -1;
    }
    else{
        return ans;
    }
}
