//https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?topList=cracking-the-coding-interview-questions
/*

4
1 2 3

j=1
dp[1] = 1
dp[2] = 2
dp[3] = 1
dp[4] = 1

dp[val] = dp[val-1] + dp[val-2] + ....



*/
#include<vector>



long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    //dp[i]->ways to make change of i
    
    //dp[val] = sum(dp[val-denom[i]])
    vector<long>dp(value+1,0);
    dp[0] = 1;
    
  //1 2 3
    for(int i=0;i<n;i++){
        for(int j = denominations[i];j<=value;j++){
            dp[j]+=dp[j-denominations[i]];
        }
    }
    return dp[value];
    
}
