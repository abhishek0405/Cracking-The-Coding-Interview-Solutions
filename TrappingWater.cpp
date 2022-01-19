//https://www.codingninjas.com/codestudio/problems/trapping-rainwater_630519?topList=cracking-the-coding-interview-questions
/*
3 0 0 2 4

5 7 0 2 3



*/
long getTrappedWater(long *arr, int n){
   
    long leftMax = 0;
    long rightMax = 0;
    int left = 0;
    int right = n-1;
    long ans = 0;
    
    while(left<=right){
        //water stored wrt rightmax
        // as left counterpart is more
        // so can balance
        if(arr[left]>=arr[right]){
            if(arr[right]>=rightMax){
                rightMax = arr[right];
            }
            else{
                ans+=rightMax-arr[right];
            }
            right--;
        }
        
        else{
            if(arr[left]>=leftMax){
                leftMax = arr[left];
            }
            else{
                ans+=leftMax - arr[left];
            }
            left++;
        }
    }
    return ans;
}
