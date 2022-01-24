/*
3 3 3 3 5 5 5 5 5 5 3 3 
4 4 4 4 5 5 5 5
*/
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    int currElement = arr[0];
    int currCount = 1;
    for(int i=1;i<n;i++){
        if(arr[i]==currElement){
            currCount++;
        }
        else{
            currCount--;
            if(currCount==0){
                currElement = arr[i];
                currCount = 1;
            }
        }
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==currElement){
            count++;
        }
    }
    
    if(count>n/2){
        return currElement;
    }
    else{
        return -1;
    }
}
