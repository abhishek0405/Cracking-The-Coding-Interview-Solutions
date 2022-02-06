//https://www.codingninjas.com/codestudio/problems/ninja-and-his-meetings_1263693?topList=cracking-the-coding-interview-questions
/*
  30 15 60 75  45   15  15  45

0 30 15 90 105 135  120 150 180
0 0  30 30 90  105  135 135 150

*/
int maxMinutes(vector<int>& meetings, int n) {
	// Write your code here.
//     int attended[n+1];
//     int skipped[n+1];
//     int i;
   
//     attended[0] = meetings[0];
//     skipped[0] = 0;
    
//     for(i=1;i<n;i++){
//         attended[i] = max(attended[i-1],skipped[i-1]+meetings[i]);
//         skipped[i] = max(skipped[i-1],attended[i-1]);
//     }
       int i;
       int attendMax = meetings[0];
       int prevAttendMax = meetings[0];
       int skipMax = 0;
    
       for(i=1;i<n;i++){
           prevAttendMax = attendMax;
           attendMax = max(attendMax,skipMax + meetings[i]);
           skipMax = max(skipMax,prevAttendMax);
       }
     
       
    return max(skipMax,attendMax);
}
