//Find the question below
// https://www.codingninjas.com/codestudio/problems/magic-index_1199229?topList=cracking-the-coding-interview-questions

/*
-7 -3 0  1  2 3 8 9 18 22
0  1  2  3  4 5 6 7 8 9

  5 8 
  5 6 7 8 9 10 11

  


*/

int magicIndex(vector<int> a, int n) {
	// Write your code here
    int mIndex = -1;
    int i,j,k;
    for(i=0;i<n;i++){
        if(a[i]>=0 && a[i]==i){
            return i;
        }
    }
    return mIndex;
}
