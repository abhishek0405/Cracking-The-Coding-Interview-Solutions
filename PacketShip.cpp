//https://www.codingninjas.com/codestudio/problems/capacity-to-ship-packages-within-d-days_1229379?topList=cracking-the-coding-interview-questions
/*

10,11,12,13... 52,53,54,55
*/

bool isPossible(vector<int> &weights, int d,int mid){
    int n = weights.size();
    int i,j,currSum,currDays;
    currSum = 0;
    currDays = 1;
    
  	for(i=0;i<n;i++){
        
      if(weights[i]>mid){
          return false;
      }
      
      if(currSum+weights[i]>mid){
          currDays++;
          currSum = weights[i];
          if(currDays>d){
              return false;
          }
      }
      else{
            currSum+=weights[i];
      }
        
        
   }
    
    return true;
    
    
    
    
}
int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    
    int st,end,mid,n,i,ans;
    n = weights.size();
    
    st = 0;
    end = 0;
    for(i=0;i<n;i++){
        st = max(st,weights[i]);
        end+=weights[i];
    }
    
    //st is max weight 
    //end is sum of all weights
    
    
    while(st<=end){
        mid = (st+end)/2;
        
        if(isPossible(weights,d,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            st = mid+1;
        }
    }
    
    return ans;
    
}
